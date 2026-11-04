# 4098. Minimize the Maximum Value of GCD-Connected Array  [Medium]

https://leetcode.com/problems/minimize-the-maximum-value-of-gcd-connected-array/

You are given three integers `n`, `index`, and `value`.

An integer array `nums` of length `n` is called **GCD-Connected** if:

- `nums[i] > 0` for `0 <= i <= n - 1`.
- `nums[i] < nums[i + 1]` for `0 <= i <= n - 2`.
- `nums[index] = value`.
- `gcd(nums[i], nums[i + 1]) > 1` for `0 <= i <= n - 2`.

Return the minimum possible maximum value, `nums[n - 1]`, among all GCD-Connected arrays `nums`. If no such array exists, return `-1`.

### Example 1

```text
Input: n = 4, index = 2, value = 8
Output: 10
Explanation:
  - The GCD-Connected array will look like: nums = [?, ?, 8, ?] since nums[2] = 8.
  - Since nums[3] > 8 and gcd(8, 9) = 1, every valid GCD-Connected array must have nums[3] >= 10.
  - One optimal array satisfying all conditions is [2, 4, 8, 10].
  - Thus, the minimum possible value of nums[3] is 10.
```

### Example 2

```text
Input: n = 2, index = 1, value = 3
Output: -1
Explanation:
  - The GCD-Connected array will look like: nums = [?, 3] since nums[1] = 3.
  - Since we need 0 < nums[0] < nums[1] = 3, there are only two possible arrays: [1, 3] and [2, 3].
    Neither of them satisfies gcd(nums[0], nums[1]) > 1.
  - Therefore, no valid GCD-Connected array exists, and the answer is -1.
```

### Example 3

```text
Input: n = 2, index = 0, value = 3
Output: 6
Explanation:
  - The GCD-Connected array will look like: nums = [3, ?] since nums[0] = 3.
  - Since nums[1] > 3 and gcd(3, 4) = gcd(3, 5) = 1, every valid GCD-Connected array must have nums[1] >= 6.
  - One optimal array is [3, 6].
  - Thus, the minimum possible value of nums[1] is 6.
```

### Constraints

- `2 <= n <= 10^9`
- `1 <= value <= 10^9`
- `0 <= index <= n - 1`
