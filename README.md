# LeetCode in C++

My LeetCode practice setup. Solutions are written to be pasted straight into the judge, but
each one also runs locally against its own test suite under a debugger.

## Layout

Every problem is three files in a topic folder, named after the problem:

```
Graphs/Minimum Cost to Reach City With Discounts.cpp         <- the solution, and only the solution
Graphs/Minimum Cost to Reach City With Discounts.md          <- the problem statement
Graphs/Minimum Cost to Reach City With Discounts.test.cpp    <- the local test suite
```

The `.cpp` holds nothing but the `Solution` class, so it pastes into LeetCode unchanged. The
`.test.cpp` `#include`s it and supplies `main`.

## Setup

Install the local prerequisites before using the VS Code buttons:

- macOS Clang with C++23 support;
- VS Code and the `code` command;
- Claude Code, if using the Claude analysis option;
- Codex CLI, if using the Codex analysis option.

Authenticate the CLIs through their normal login flows, then run this from the repository root:

```sh
./tools/leetcode-buttons/build.sh
```

The build script packages and installs the VS Code extension and synchronizes the shared
`leetcode-analysis` skill into both `~/.claude/skills/leetcode-analysis/` and
`~/.codex/skills/leetcode-analysis/`. After installation, run **Developer: Reload Window** from
the VS Code Command Palette. Open any `.cpp` or `.md` problem file; the Run, Debug, and sparkle
Analyze buttons should appear in the editor title bar and status bar.

## Running

```sh
./run.sh "Graphs/Minimum Cost to Reach City With Discounts.cpp"   # build + run all tests
./run.sh --build "<file>"                                         # build only
TEST=14 ./run.sh "<file>"                                         # run just test #14
```

`run.sh` accepts any of the three files for a problem. It compiles with `clang++ -std=c++23`,
UBSan and libc++ hardened bounds checks, and puts the binary in `~/Library/Caches/leetcode_cpp/`.

## include/leetcode.h

Force-included into every build, so solution files need no `#include`s of their own. It provides
`bits/stdc++.h`, `using namespace std`, LeetCode's `ListNode`/`TreeNode`, builders (`makeList`,
`makeTree`), `operator<<` for containers/lists/trees, `dbg(...)`, and the test harness:
`TestRunner` plus `expectEq`, `expectAnyOrder`, `expectAnyOrderDeep`, `expectClose`,
`expectOneOf`, `expectValid` and `noCheck`.

## tools/leetcode-buttons

A small local VS Code extension adding editor-title and status-bar buttons: run all tests, run a
single test, debug, analyze the active solution, open the problem description, and open the tests.
Run its `build.sh` after editing.

### Solution analysis

The **Analyze** button asks whether to run the shared analysis skill with Claude or Codex. It
opens the selected CLI in the VS Code integrated terminal, compiles the active problem's tests
with `clang++ -O2` and without sanitizers, runs the complete hidden test suite, and supplies the
results to the analysis skill. The report covers expected and actual time/space complexity,
correctness observations, measured wall time, and peak memory, followed by one or two concise
optimization suggestions.

Reports are saved for future use under `Questions/<Problem Title>/`:

```
Questions/Sliding Window/Subarrays with K Different Integers/analysis.codex.md
Questions/Sliding Window/Subarrays with K Different Integers/analysis.claude.md
```

If the problem, solution, tests, benchmark settings, and provider are unchanged, Analyze opens
the cached report without invoking a model again. The report is shown in a separate formatted
Webview panel with a Close button. Claude Code and Codex must be installed and authenticated
locally for their respective options.
