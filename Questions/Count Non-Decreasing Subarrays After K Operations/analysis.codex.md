<!-- leetcode-analysis: provider=codex fingerprint=76c68fd46026d720d6f4474936e57ae60a295a5d1563e4566459d433fa410a66 -->

## Complexity

- **Expected optimal:** \(\Theta(n)\) time and \(O(n)\) auxiliary space.
- **Actual:** \(\Theta(n)\) worst-case time. Prefix sums, the next-greater monotonic stack, backward preprocessing, and the sliding window are each linear; every index is pushed and removed at most once.
- **Actual auxiliary space:** \(O(n)\) for three arrays, the stack, and the deque. This matches the expected asymptotic bound, though with relatively large constants.

## Measured performance

Local release-like benchmark:

- **Tests:** 18/18 passed.
- **Total wall time:** 0.18 s.
- **Largest timed cases:** 0.3 ms each for both 30,000-element tests.
- **Maximum resident set size:** 2,621,440 bytes (2.50 MiB).
- **Reported peak memory footprint:** 2,146,688 bytes (2.05 MiB).

These measurements do not establish the asymptotic bounds; those follow from the code structure.

## Correctness

The implementation appears correct for the stated contract and complete hidden suite.

- It handles singleton, increasing, equal, decreasing, spike/valley, and alternating inputs.
- All cost, prefix-sum, running-maximum-sum, and answer calculations use `long long`, safely covering values up to roughly \(10^{14}\) and avoiding 32-bit overflow.
- The sliding window remains valid because removing elements cannot increase the required increment cost.
- `nums` is not mutated.
- Access to `nums[0]` assumes `n >= 1`, which is guaranteed by the constraints.

## Suggestions

- Replace the `stack<int>` adapter with a reserved `vector<int>` used as a stack for better locality and lower allocation overhead.
- If memory constants matter, compute the window cost directly with a monotonic-deque formulation, eliminating the `prefixsum`, `nextGreaterIndex`, and `sumOfRunningMax` buffers while retaining \(O(n)\) time.
