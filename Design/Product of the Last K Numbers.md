# 1352. Product of the Last K Numbers  [Medium]

https://leetcode.com/problems/product-of-the-last-k-numbers/

Design an algorithm that accepts a stream of integers and retrieves the product of the last `k` integers of the stream.

Implement the `ProductOfNumbers` class:

- `ProductOfNumbers()` initializes the object with an empty stream.
- `void add(int num)` appends the integer `num` to the stream.
- `int getProduct(int k)` returns the product of the last `k` numbers in the current list. You can assume that the current list has at least `k` numbers.

The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

### Example 1

```text
Input:
["ProductOfNumbers", "add", "add", "add", "add", "add", "getProduct", "getProduct", "getProduct", "add", "getProduct"]
[[], [3], [0], [2], [5], [4], [2], [3], [4], [8], [2]]
Output:
[null, null, null, null, null, null, 20, 40, 0, null, 32]

Explanation:
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20
productOfNumbers.getProduct(3); // return 40
productOfNumbers.getProduct(4); // return 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32
```

### Constraints

- `0 <= num <= 100`
- `1 <= k <= 4 * 10^4`
- At most `4 * 10^4` calls will be made to `add` and `getProduct`.
- The product of the stream at any point in time will fit in a 32-bit integer.

### Follow-up

Can you implement both `getProduct` and `add` to work in `O(1)` time complexity instead of `O(k)` time complexity?
