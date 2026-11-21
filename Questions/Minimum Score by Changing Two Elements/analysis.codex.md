<!-- leetcode-analysis: provider=codex fingerprint=0af72697213c31ec9254d294d6049f566a26c4ff4e2e83f3e95185f4086249ab -->

## Complexity

- Expected optimal: `O(n)` time and `O(1)` auxiliary space.
- Actual: `O(n log n)` time, dominated by `std::sort`. The two median-based scans can each take `O(n)`.
- Actual auxiliary space: typically `O(log n)` for the sorting call stack. The input array is sorted in place.

## Measured performance

Supplied local release-like benchmark:

- Hidden tests: 14/14 passed.
- Full-suite wall time: 0.11 s.
- Largest individual test time: 3.1 ms for 100,000 random values.
- Maximum resident set size: 2,064,384 bytes, approximately 1.97 MiB.
- Reported peak memory footprint: 1,589,632 bytes, approximately 1.52 MiB.

These measurements include the test runner and do not establish asymptotic complexity.

## Correctness

The implementation passes the complete supplied suite, but it is not correct for every valid input.

For `nums = [1,2,3,3]`, changing `1` and `2` to `3` produces score `0`, while the implementation returns `1`. The median-based skipping logic fails to consider removing both low extremes when the truncated even-length median happens to equal an existing value.

Indexing and integer arithmetic are safe under the stated constraints. The function does mutate `nums` by sorting it.

## Suggestions

- Replace the median-based scans with direct evaluation of the three possible ways to remove two sorted extremes; this fixes the correctness gap.
- To reach `O(n)` time and `O(1)` space, track only the three smallest and three largest values instead of sorting the entire array.
