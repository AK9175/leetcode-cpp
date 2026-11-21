<!-- leetcode-analysis: provider=codex fingerprint=ed4915f78511ff494bde13d2feaab6ba8afae1c7fa6b649e4542eea362b2cc2b -->

## Complexity

- Expected optimal: `O(n)` time and `O(1)` auxiliary space.
- Actual: `O(n)` time. The implementation makes one pass to build two prefix-count arrays and a second pass over the character pairs.
- Actual auxiliary space: `O(n)` for the `ones` and `zeroes` vectors. Passing `s` by value may also copy `O(n)` characters.

## Measured performance

Local release-like benchmark:

- Result: 11/11 tests passed.
- Overall wall time: 0.23 seconds.
- Length-100,000 cases: 0.4 ms (all zeros), 0.6 ms (alternating), and 0.5 ms (random).
- Peak memory footprint: 3,326,336 bytes (about 3.17 MiB).
- Maximum resident set size: 3,784,704 bytes (about 3.61 MiB).

These measurements do not establish asymptotic complexity.

## Correctness

The implementation appears correct for the stated contract and complete supplied suite. A beautiful string requires each fixed pair `(s[0], s[1])`, `(s[2], s[3])`, and so on to match. The prefix-count differences correctly determine whether each pair costs zero or one change.

The minimum and maximum permitted lengths are handled, the answer cannot overflow an `int` under `n <= 10^5`, and the input is not mutated. The code relies appropriately on the contract that the length is even and every character is binary.

## Suggestions

- Compare each adjacent pair directly and increment the answer when they differ; this removes both prefix arrays and reduces auxiliary space to `O(1)`.
- If the required interface permits it, accept the string by `const string&` to avoid copying the input.
