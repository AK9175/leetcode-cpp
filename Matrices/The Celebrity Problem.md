# The Celebrity Problem  [Medium]

https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

GeeksforGeeks, not LeetCode. The LeetCode twin is [277. Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/), which is premium-locked and hides the matrix behind a `bool knows(a, b)` API; this version hands you the matrix directly and allows `n == 1`.

A celebrity is a person who is known to all but does not know anyone at a party.

Given a square matrix `mat[][]` of size `n x n`, where `mat[i][j] = 1` means person `i` knows person `j`, and `mat[i][j] = 0` means person `i` does not know person `j`, return the index of the celebrity. If no celebrity exists, return `-1`.

Note that `mat[i][i] = 1` for all `i`: everyone knows themselves, and this does not disqualify anyone from being a celebrity.

### Example 1

```text
Input: mat[][] = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
Output: 1
Explanation: Person 1 is known by both person 0 and person 2, and person 1 knows nobody else.
```

### Example 2

```text
Input: mat[][] = [[1, 1], [1, 1]]
Output: -1
Explanation: Both persons know each other, so neither can be a celebrity.
```

### Example 3

```text
Input: mat[][] = [[1]]
Output: 0
Explanation: There is only one person, who trivially knows nobody else and is known by nobody else.
```

### Constraints

- `1 <= mat.size() == mat[i].size() <= 1000`
- `0 <= mat[i][j] <= 1`
- `mat[i][i] = 1`

### Expected Complexities

- Time: `O(n)`
- Space: `O(1)`
