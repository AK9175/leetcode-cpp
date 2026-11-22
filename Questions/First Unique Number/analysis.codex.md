<!-- leetcode-analysis: provider=codex fingerprint=9273ec5a0652372b89bb129f218356a21a6f99e48506012f846fc66593bf35fc -->

## Complexity

Let `n` be the initial length, `a` the number of `add` calls, and `d` the number of distinct values.

- **Expected optimal:** `O(n)` initialization, `O(1)` average time per `add` and `showFirstUnique`, and `O(d)` auxiliary space.
- **Submitted solution:** `O(n)` expected initialization and `O(1)` expected amortized `add`. One `showFirstUnique` can take `O(n+a)` time while it removes stale queue entries, but each entry is removed once, giving `O(1)` amortized time per call across the operation sequence. The queue stores every occurrence, so auxiliary space is `O(n+a)`.

## Measured performance

The supplied local benchmark passed **17/17 tests**. Total wall time was **0.18 s**; peak memory footprint was **7,520,640 bytes** (about **7.17 MiB**). These measurements do not establish asymptotic complexity.

## Correctness

The implementation appears correct for the stated contract and all supplied tests. Repeated queries preserve the result, and later occurrences cannot make a value unique again. The maximum possible count under the constraints fits in `int`.

## Suggestions

- Queue a value only on its first occurrence, and store the value directly instead of a `{value, 1}` pair. This reduces queue memory, especially with many duplicates.
- If each query needs `O(1)` average time without an occasional long cleanup, maintain the currently unique values in an ordered list with map entries for removal.
