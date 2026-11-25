# 3934. Smallest Unique Subarray  [Hard]

https://leetcode.com/problems/smallest-unique-subarray/

You are given an integer array `nums`.

Find the minimum length of a subarray that is not identical to any other subarray in `nums`.

Return an integer denoting the minimum possible length of such a subarray.

Two subarrays are considered identical if they have the same length and the same elements in corresponding positions.

### Example 1

```text
Input: nums = [3,3,3]
Output: 3

Explanation:
Subarrays of length 1: [3] appears 3 times.
Subarrays of length 2: [3,3] appears 2 times.
Subarrays of length 3: [3,3,3] appears once.
```

### Example 2

```text
Input: nums = [2,1,2,3,3]
Output: 1

Explanation:
The subarray [1] appears once, while [2] and [3] each appear more than once.
```

### Example 3

```text
Input: nums = [1,1,2,2,1]
Output: 2

Explanation:
Every subarray of length 1 is repeated. At length 2, there are subarrays that appear once.
```

### Constraints

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
