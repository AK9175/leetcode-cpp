<!-- leetcode-analysis: provider=codex fingerprint=7d567cc9f264705e2bdc6b8ad13bb09f9893d4dabda1dacf8d2a1c45e5c5d81b -->

## Complexity

- **Expected:** `O(1)` time per `add` and `getProduct`, with `O(n)` auxiliary space for `n` additions.
- **Actual:** `getProduct` is `O(1)`. `add` is amortized `O(1)`, but a vector reallocation can make one call `O(n)`. The prefix vector uses `O(n)` space.

## Measured performance

All 9 supplied tests passed. The local benchmark reports **0.30 s wall time** for the run, with the largest individual test reported as **0.3 ms**. Peak memory footprint was **2,032,000 bytes** (about **1.94 MiB**). These measurements do not establish asymptotic complexity.

## Correctness

The zero tracking and prefix division appear correct for the stated contract, including the tested zero and maximum length cases. The contiguous product guarantee keeps the stored products within `int` range. When `k` equals the stream length, however, unsigned subtraction underflows before conversion to `int`; the expected `-1` result is implementation dependent.

## Suggestions

1. Use signed arithmetic for the query boundary to remove that portability risk.
2. Reserve capacity for the stated operation limit if worst-case latency from `add` reallocations matters.
