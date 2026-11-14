#!/usr/bin/env bash
set -euo pipefail

# Run a release-like local benchmark, then invoke the selected analysis skill.
# Usage: analyze.sh <claude|codex> <solution-base> <report-path> <fingerprint> <prompt-file>

if [[ $# -ne 5 ]]; then
    echo "usage: $0 <claude|codex> <solution-base> <report-path> <fingerprint> <prompt-file>" >&2
    exit 2
fi

PROVIDER="$1"
BASE="$2"
REPORT="$3"
FINGERPRINT="$4"
PROMPT_FILE="$5"

# The extension runs from its installed VSIX directory, so locate the repository
# from the active problem path rather than from this script's own directory.
BASE="$(cd "$(dirname "$BASE")" && pwd)/$(basename "$BASE")"
ROOT="$(dirname "$BASE")"
while [[ "$ROOT" != "/" && ! -f "$ROOT/run.sh" ]]; do
    ROOT="$(dirname "$ROOT")"
done
if [[ ! -f "$ROOT/run.sh" ]]; then
    echo "Could not locate the LeetCode workspace root from $BASE" >&2
    exit 2
fi

TMP_DIR="$(mktemp -d "${TMPDIR:-/tmp}/leetcode-analysis.XXXXXX")"
trap 'rm -rf "$TMP_DIR"' EXIT

BIN="$TMP_DIR/tests"
BENCHMARK="$TMP_DIR/benchmark.txt"
RAW="$TMP_DIR/raw.md"
REPORT_TMP="$REPORT.tmp.$$"
mkdir -p "$(dirname "$REPORT")"

echo "[leetcode] compiling release-like benchmark with -O2 and no sanitizers"
set +e
clang++ -std=c++23 -O2 -DNDEBUG -Wall -Wextra -Wshadow -Wno-unused-parameter \
    -DLOCAL -I "$ROOT/include" -include "$ROOT/include/leetcode.h" \
    "$BASE.test.cpp" -o "$BIN" >"$TMP_DIR/compile.txt" 2>&1
COMPILE_STATUS=$?
set -e

if [[ $COMPILE_STATUS -ne 0 ]]; then
    {
        echo "Compilation failed with exit code $COMPILE_STATUS."
        cat "$TMP_DIR/compile.txt"
    } >"$BENCHMARK"
    echo "[leetcode] benchmark compilation failed; analysis will still report the failure"
else
    echo "[leetcode] running tests and measuring runtime/peak memory"
    set +e
    /usr/bin/time -l "$BIN" >"$BENCHMARK" 2>&1
    RUN_STATUS=$?
    set -e
    if [[ $RUN_STATUS -ne 0 ]]; then
        printf '\nTest process exited with code %s.\n' "$RUN_STATUS" >>"$BENCHMARK"
    fi
fi

PROMPT="$(cat "$PROMPT_FILE")"
BENCHMARK_TEXT="$(cat "$BENCHMARK")"
FULL_PROMPT="$PROMPT

The release-like benchmark output is below. Use it only for measured runtime and peak memory; do not treat it as proof of asymptotic complexity.

--- benchmark output ---
$BENCHMARK_TEXT
--- end benchmark output ---

Use the leetcode-analysis skill. Return only the requested Markdown analysis. Do not edit files."

echo "[leetcode] running $PROVIDER analysis skill"
set +e
if [[ "$PROVIDER" == "claude" ]]; then
    claude --print --permission-mode dontAsk --no-session-persistence --add-dir "$ROOT" "$FULL_PROMPT" | tee "$RAW"
    ANALYSIS_STATUS=${PIPESTATUS[0]}
elif [[ "$PROVIDER" == "codex" ]]; then
    codex --sandbox workspace-write --ask-for-approval never -C "$ROOT" exec "$FULL_PROMPT" | tee "$RAW"
    ANALYSIS_STATUS=${PIPESTATUS[0]}
else
    echo "Unknown provider: $PROVIDER" >&2
    exit 2
fi
set -e

if [[ $ANALYSIS_STATUS -ne 0 ]]; then
    echo "Analysis command exited with code $ANALYSIS_STATUS" >&2
    exit "$ANALYSIS_STATUS"
fi

{
    echo "<!-- leetcode-analysis: provider=$PROVIDER fingerprint=$FINGERPRINT -->"
    echo
    cat "$RAW"
} >"$REPORT_TMP"
mv "$REPORT_TMP" "$REPORT"
echo "[leetcode] saved analysis to $REPORT"
