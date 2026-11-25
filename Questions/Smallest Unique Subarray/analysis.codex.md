<!-- leetcode-analysis: provider=codex fingerprint=872e2fc1a778a6994360f4df54c8ecfdc8776b7ad5e0f428f27018827f107813 -->

## Complexity

- **Expected optimal:** `O(n)` time and `O(n)` auxiliary space are achievable with a linear time suffix array and LCP computation.
- **Submitted:** Each rolling hash check takes `O(n)` expected time; binary search makes `O(log n)` checks, for `O(n log n)` expected time and `O(n)` auxiliary space. Pathological `unordered_map` bucket collisions can raise worst case time to `O(n^2 log n)`.

## Measured performance

The supplied local benchmark passed **12/12 tests**. The two length 100,000 tests took **23.7 ms** and **20.7 ms**. Full command wall time was **0.59 s**. Peak memory footprint was **2,015,592 bytes** (1.92 MiB); maximum resident set size was **2,506,752 bytes** (2.39 MiB). These measurements do not establish asymptotic complexity.

## Correctness

The solution is **not guaranteed correct**: distinct subarrays can have the same hash, causing the frequency check to miss a unique subarray. For example, `[1,1]` and `[10000,70011]` collide. On `nums = [10000,70011,1,1,70011,1,10000,1,10000,1,70011]`, the true answer is **2**, but the implementation returns **3**.

## Suggestions

- Use a suffix array with adjacent LCP values to identify the shortest unique subarray through exact comparisons. A linear time construction reaches `O(n)` time and `O(n)` space.
