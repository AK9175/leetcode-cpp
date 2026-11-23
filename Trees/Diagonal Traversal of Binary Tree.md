# Diagonal Traversal of Binary Tree  [GeeksforGeeks]

https://www.geeksforgeeks.org/dsa/diagonal-traversal-of-binary-tree/

Given a binary tree, return its diagonal traversal.

Imagine diagonal lines passing between the nodes of the binary tree. All nodes lying on the same diagonal belong to the same diagonal group.

Return a single list containing all the nodes in diagonal order, starting from the topmost diagonal and moving to the next diagonals. If nodes from the left and right subtrees belong to the same diagonal, include the nodes from the left subtree before the nodes from the right subtree.

### Example 1

```text
Input: root = [8, 3, 10, 1, 6, N, 14, N, N, 4, 7, 13]
Output: [8, 10, 14, 3, 6, 7, 13, 1, 4]
```

### Example 2

```text
Input: root = [1, 2, N, 3, N]
Output: [1, 2, 3]
```

### Expected complexity

- Time: `O(n)`
- Auxiliary space: `O(n)`
