<!-- leetcode-analysis: provider=codex fingerprint=d4c1ba024b4d7ada4c580366442b10fd1a38bc45661de6b9afba621eb2696153 -->

## Complexity

- **Expected optimal time:** `O(n log n)` for a comparison-sort-based solution. The bounded value range also permits `O(n + U)` using frequency-based DP, where `U <= 10^6`.
- **Actual time:** `O(n log n)`. Sorting dominates; the subsequent DP scan is `O(n)`.
- **Expected optimal auxiliary space:** `O(log n)` with in-place comparison sorting, including the sort stack.
- **Actual auxiliary space:** `O(log n)` from `std::sort`; the rolling DP variables use `O(1)` space.

## Measured performance

Local release-like benchmark results:

- **Tests:** 13/13 passed.
- **Whole-suite wall time:** 0.14 s.
- **Largest timed case:** 3.1 ms for 100,000 random values.
- **Maximum resident set size:** 2,048,000 bytes, about 1.95 MiB.
- **Peak memory footprint:** 1,573,248 bytes, about 1.50 MiB.

These measurements describe this benchmark run only and do not establish asymptotic complexity.

## Correctness

The implementation appears correct for the stated constraints and complete hidden suite. Its two rolling states correctly handle equal values, adjacent values, gaps of two, and disconnected ranges. It also handles duplicate saturation and the `10^6` boundary safely.

No overflow or undefined behavior is apparent under the constraints. The method does mutate `nums` by sorting it in place.

## Suggestions

- No optimization is necessary for the given limits; the current `O(n log n)` approach is compact and fast.
- If linear-time processing is required, use frequency-based DP over the bounded value domain, trading time for `O(U)` auxiliary memory.
