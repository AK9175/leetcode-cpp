<!-- leetcode-analysis: provider=codex fingerprint=620eaef7001bf3f353043e2cee83823c6c9ed6f50dca3d2abb38ebbaebd3a308 -->

## Complexity

- **Expected optimal:** `O(h + k)` time and `O(h)` auxiliary space, where `h` is tree height. For the balanced-tree follow-up, this becomes `O(log n + k)` time and `O(log n)` space. The returned result requires `O(k)` additional output space.
- **Actual time:** `O(n + log n + k) = O(n)`. The inorder traversal visits all `n` nodes, `lower_bound` costs `O(log n)`, and selecting the result costs `O(k)`.
- **Actual auxiliary space:** `O(n + h)` excluding the returned result: `arr` stores all `n` values and recursion uses `O(h)` stack frames. This is `O(n)` overall, including on the `10,000`-node chain. `ans` adds `O(k)` output space.

## Measured performance

Local release-like benchmark results:

- **Tests:** 17/17 passed
- **Wall-clock runtime:** 0.54 seconds for the runner process
- **Largest reported individual tests:** 0.3 ms balanced tree; 0.4 ms chain
- **Peak memory footprint:** 3,031,424 bytes (~2.89 MiB)
- **Maximum resident set size:** 3,522,560 bytes (~3.36 MiB)

These measurements describe this test run only and do not establish asymptotic complexity.

## Correctness

The implementation is correct for the stated constraints and all supplied tests, including boundary targets, `k = n`, values near `10^9`, balanced trees, and a maximally skewed tree.

One lifecycle issue remains: `arr` and `ans` are member variables and are never cleared. Calling `closestKValues` more than once on the same `Solution` object would retain old data, potentially violate `lower_bound`’s sorted-range requirement, and return accumulated answers. The supplied tests avoid this by constructing a new `Solution` for every call.

## Suggestions

- Use predecessor and successor traversal stacks initialized along the BST search path, then extract `k` values in `O(h + k)` time and `O(h)` auxiliary space.
- If retaining this approach, clear `arr` and `ans` at the beginning of each call and consider iterative inorder traversal to avoid deep recursion on skewed trees.
