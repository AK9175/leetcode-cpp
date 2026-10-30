#!/usr/bin/env bash
# Compile and run a LeetCode C++ solution.
#
#   ./run.sh <file> [input.txt]     build (debug + sanitizers) and run
#   ./run.sh --build <file>         build only (used by the VS Code debugger)
#   TEST=3 ./run.sh <file>          run only test #3
#
# <file> may be a problem's X.cpp, X.md or X.test.cpp. When X.test.cpp exists it is
# what gets compiled (it #includes X.cpp); otherwise X.cpp is compiled on its own.
#
# The binary goes to ~/Library/Caches/leetcode_cpp/current, outside Desktop, so macOS
# does not ask for Desktop access every time a rebuilt binary runs.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

BUILD_ONLY=0
if [[ "${1:-}" == "--build" ]]; then
    BUILD_ONLY=1
    shift
fi

if [[ $# -lt 1 ]]; then
    echo "usage: $0 [--build] <file.cpp> [input.txt]" >&2
    exit 1
fi

SRC="$(cd "$(dirname "$1")" && pwd)/$(basename "$1")"
INPUT="${2:-}"

BASE="${SRC%.md}"
BASE="${BASE%.cpp}"
BASE="${BASE%.test}"
if [[ -f "$BASE.test.cpp" ]]; then
    SRC="$BASE.test.cpp"
else
    SRC="$BASE.cpp"
fi
REL="${BASE#"$ROOT"/}"

BUILD_DIR="$HOME/Library/Caches/leetcode_cpp"
OUT="$BUILD_DIR/current"
mkdir -p "$BUILD_DIR"

FLAGS=(
    -std=c++23
    -g -O0
    -Wall -Wextra -Wshadow -Wno-unused-parameter
    -fsanitize=undefined              # int overflow, bad shifts, null deref, etc.
    -D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_DEBUG  # bounds-checks vector[], string[], front() on empty...
    # (AddressSanitizer is skipped: it hangs on startup with Apple clang 17 on this macOS)
    -fno-omit-frame-pointer
    -fcolor-diagnostics
    -DLOCAL
    -I "$ROOT/include"
    -include "$ROOT/include/leetcode.h"
)

clang++ "${FLAGS[@]}" "$SRC" -o "$OUT"

[[ $BUILD_ONLY -eq 1 ]] && exit 0

echo "──── running ${REL}${TEST:+ (test #$TEST)} ────"
if [[ -n "$INPUT" ]]; then
    "$OUT" < "$INPUT"
else
    "$OUT"
fi
