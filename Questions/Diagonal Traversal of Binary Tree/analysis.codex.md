<!-- leetcode-analysis: provider=codex fingerprint=26f5680012b745f3e67672d7016d6e20995974cf87662b93e008f54a1d487c7b -->

## Complexity

- **Expected:** `O(n)` time and `O(n)` auxiliary space.
- **Actual:** `O(n)` time. Each node is visited once, and each left child is queued once. The queue uses `O(n)` auxiliary space in the worst case; the returned vector also holds `O(n)` values.

## Measured performance

The supplied local benchmark passed **10/10 tests**. It reported **0.22 s** elapsed for the full run and **2.6 ms** for the 100,000-node right-chain test. Peak memory footprint was **5,374,336 bytes (5.13 MiB)**. These measurements do not establish asymptotic complexity.

## Correctness

The solution appears correct for the stated diagonal order. The suite covers empty and single-node trees, both chain directions, mixed branches, and duplicate values. The large right-chain test checks output length only, not every value.

## Suggestions

The solution already meets the expected bounds. An early return for a null root would avoid one unnecessary queue iteration.
