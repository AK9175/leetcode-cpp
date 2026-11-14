<!-- leetcode-analysis: provider=codex fingerprint=2cfc599a45adcd5db1dbae72ad9305781c35a460f1e086fdb87f00138611a3fe -->

## Complexity

- **Expected optimal time:** \(O(n)\).
- **Actual time:** \(O(n)\) expected. `atmost` makes one sliding-window pass, and it is called twice; each pointer advances at most \(n\) times. Hash-table operations are \(O(1)\) average, but `unordered_map` gives a theoretical \(O(n^2)\) worst case under severe collisions.
- **Expected optimal auxiliary space:** \(O(n)\) under the stated value range.
- **Actual auxiliary space:** \(O(d)\), where \(d\) is the number of distinct values encountered; therefore \(O(n)\) worst case. Zero-frequency map entries are retained.

## Measured performance

Local release-like benchmark:

- **Tests:** 16/16 passed.
- **Large-case runtime (\(n=20{,}000\)):** 1.0–3.1 ms per test.
- **Whole runner wall time:** 0.60 s.
- **Peak memory footprint:** 2,408,832 bytes (about 2.30 MiB).
- **Maximum resident set size:** 2,883,584 bytes (about 2.75 MiB).

These measurements do not establish asymptotic complexity.

## Correctness

The implementation appears correct for the stated contract. It correctly computes `atMost(k) - atMost(k - 1)`, including `k = 1`, where `atmost(0)` contributes zero. The supplied tests cover repeated values, all-distinct arrays, oversized `k`, and maximum-length inputs.

The maximum answer is \(n(n+1)/2 = 200{,}010{,}000\) for \(n=20{,}000\), so the signed `int` accumulator is safe under the constraints. `nums` is not mutated despite being passed by non-const reference.

## Suggestions

- Replace `unordered_map` with a frequency vector of size `nums.size() + 1`; the constraints guarantee values in `[1, n]`, yielding deterministic \(O(n)\) time with lower overhead.
- Simplify `atmost` by shrinking first and then adding `right - left + 1` once per right endpoint; this preserves complexity while making the counting invariant clearer.
