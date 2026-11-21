<!-- leetcode-analysis: provider=codex fingerprint=1250bda05892fae9a232e1849f324c861c98023497993d34c0149e44ab78a8a9 -->

## Complexity

- **Expected optimal time:** \(O(n)\), since every element must be examined.
- **Actual time:** \(O(n)\) worst case. Initializing three length-\(n\) vectors and scanning the array dominate the work.
- **Expected optimal auxiliary space:** \(O(1)\).
- **Actual auxiliary space:** \(O(n)\) for `prefix`, `odd`, and `even`.

## Measured performance

Local release-like benchmark results:

- **Tests:** 13/13 passed.
- **Wall time:** 0.09 s for the complete suite.
- **Large-test runtime:** 0.5–0.8 ms per 100,000-element case.
- **Peak memory footprint:** 2,802,048 bytes (about 2.67 MiB).
- **Maximum resident set size:** 3,260,416 bytes (about 3.11 MiB).

These measurements do not establish the asymptotic complexity.

## Correctness

The implementation appears correct for the stated constraints and all hidden tests.

- Handles single-element, all-even, all-odd, alternating, and maximum-length inputs.
- The prefix sum is at most \(10^7\), so `int` does not overflow.
- `ans` is reduced modulo \(10^9+7\) after each update, avoiding count overflow.
- It does not mutate `arr`.
- Accessing `arr[0]` is safe because the contract guarantees at least one element.

## Suggestions

- Remove the `prefix`, `odd`, and `even` vectors. Track only the current prefix parity and the counts of previous even/odd prefixes, reducing auxiliary space from \(O(n)\) to \(O(1)\).
