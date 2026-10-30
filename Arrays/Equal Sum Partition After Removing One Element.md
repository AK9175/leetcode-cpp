# Equal Sum Partition After Removing One Element  [Medium-Hard]

Google-style interview problem (not on LeetCode).

You are given an integer array `nums` of length `n`.

You must remove **exactly one** element from the array. After the removal, the remaining elements keep their original relative order.

Determine whether the resulting array can be divided into exactly two **non-empty contiguous** subarrays whose sums are equal.

Return `true` if at least one valid removal and partition exists, otherwise return `false`.

Rules:

1. Exactly one element must be removed.
2. The removed element may be at any index.
3. Both resulting subarrays must be non-empty.
4. The remaining elements keep their original relative order.
5. Negative numbers, positive numbers and zeros are all allowed.
6. Return a boolean, not the removed index.

### Example 1

```text
Input: nums = [1,2,5,1,2]
Output: true
Explanation: Remove 5, producing [1,2,1,2]. Split into [1,2] and [1,2], both summing to 3.
```

### Example 2

```text
Input: nums = [1,2,3,4,6]
Output: true
Explanation: Remove 4, producing [1,2,3,6]. Split into [1,2,3] and [6], both summing to 6.
```

### Example 3

```text
Input: nums = [1,2,4]
Output: false
Explanation: No single removal produces two non-empty subarrays with equal sums.
```

### Example 4

```text
Input: nums = [0,0,0]
Output: true
Explanation: Remove any zero and partition the remaining two zeros.
```

### Constraints

- `3 <= nums.length <= 10^5`
- `-10^6 <= nums[i] <= 10^6`
- Sums do not fit in 32 bits; use 64-bit arithmetic.

### Target complexity

`O(n)` time.
