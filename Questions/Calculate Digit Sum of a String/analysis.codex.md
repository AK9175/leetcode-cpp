<!-- leetcode-analysis: provider=codex fingerprint=0b4cd7607d15d644eabf2a944a6a8fa955048193bdd6835c53ba2538ef451b5a -->

## Complexity

- **Expected optimal time:** \(\Theta(n)\), since the input digits must be processed.
- **Actual time:** \(\Theta(n)\) amortized. Each round scans its current string and appends group sums; the total size of all intermediate strings is linear because they progressively contract. `to_string`, appends, and `s = ans` remain linear in aggregate.
- **Expected optimal auxiliary space:** \(O(1)\) beyond the mutable input/result string, achievable with in-place read/write indices.
- **Actual auxiliary space:** \(O(n)\). `ans` stores the next round while `s` still holds the current round; temporary numeric strings use only \(O(\log k)\) space.

## Measured performance

Local release-like benchmark:

- **Tests:** 12/12 passed.
- **Whole-run wall time:** 0.17 seconds; individual cases rounded to 0.0 ms.
- **Maximum resident set size:** 1,622,016 bytes (about 1.55 MiB).
- **Peak memory footprint:** 1,163,624 bytes (about 1.11 MiB).

These measurements include the test runner and do not establish asymptotic complexity.

## Correctness

The implementation appears correct for the stated constraints and complete hidden suite. It handles no-round inputs, partial final groups, multi-digit sums, repeated rounds, and zero-heavy inputs correctly. The maximum group sum is 900, so `int` cannot overflow. Passing `s` by value also avoids mutating the caller’s string.

## Suggestions

- Write each round back into `s` with read/write indices and then resize it, reducing auxiliary space from \(O(n)\) to \(O(1)\) beyond the result buffer.
- If retaining `ans`, reserve capacity and swap it with `s` after each round to avoid avoidable reallocations and full-string assignment.
