// Hidden judge for "Sum of Sortable Integers.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Sum of Sortable Integers.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {3, 1, 2};
        return expectEq(Solution().sortableIntegers(nums), 3);
    });

    T.test("Example 2", [] {
        vector<int> nums = {7, 6, 5};
        return expectEq(Solution().sortableIntegers(nums), 0);
    });

    T.test("Example 3", [] {
        vector<int> nums = {5, 8};
        return expectEq(Solution().sortableIntegers(nums), 3);
    });

    T.test("single element", [] {
        vector<int> nums = {1};
        return expectEq(Solution().sortableIntegers(nums), 1);
    });

    T.test("already sorted, n = 6", [] {
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        return expectEq(Solution().sortableIntegers(nums), 12);
    });

    T.test("all elements equal", [] {
        vector<int> nums = {4, 4, 4, 4};
        return expectEq(Solution().sortableIntegers(nums), 7);
    });

    T.test("strictly decreasing", [] {
        vector<int> nums = {4, 3, 2, 1};
        return expectEq(Solution().sortableIntegers(nums), 0);
    });

    T.test("whole array is one rotation away, n = 5", [] {
        vector<int> nums = {3, 4, 5, 1, 2};
        return expectEq(Solution().sortableIntegers(nums), 5);
    });

    T.test("every pair swapped", [] {
        vector<int> nums = {2, 1, 4, 3, 6, 5};
        return expectEq(Solution().sortableIntegers(nums), 2);
    });

    T.test("every group of three rotated", [] {
        vector<int> nums = {2, 3, 1, 5, 6, 4};
        return expectEq(Solution().sortableIntegers(nums), 3);
    });

    T.test("block holds the right values but no rotation fits", [] {
        vector<int> nums = {2, 1, 3, 4, 5, 6};
        return expectEq(Solution().sortableIntegers(nums), 2);
    });

    T.test("duplicates, two divisors work", [] {
        vector<int> nums = {1, 1, 2, 1};
        return expectEq(Solution().sortableIntegers(nums), 6);
    });

    T.test("duplicates, nothing works", [] {
        vector<int> nums = {2, 1, 2, 1};
        return expectEq(Solution().sortableIntegers(nums), 0);
    });

    T.test("both extreme values", [] {
        vector<int> nums = {100000, 1};
        return expectEq(Solution().sortableIntegers(nums), 2);
    });

    T.test("max n, already sorted (timing check)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; ++i) nums[i] = i + 1;
        // Sorted input makes every divisor of 100000 sortable; their sum is 246078.
        return expectEq(Solution().sortableIntegers(nums), 246078);
    });

    T.test("max n, all elements equal (timing check)", [] {
        vector<int> nums(100000, 50000);
        return expectEq(Solution().sortableIntegers(nums), 246078);
    });

    T.test("max n, strictly decreasing (timing check)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; ++i) nums[i] = 100000 - i;
        return expectEq(Solution().sortableIntegers(nums), 0);
    });

    T.test("max n, every block of 100 rotated by one (timing check)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; ++i) nums[i] = i + 1;
        for (int i = 0; i < 100000; i += 100) rotate(nums.begin() + i, nums.begin() + i + 1, nums.begin() + i + 100);
        return expectEq(Solution().sortableIntegers(nums), 100);
    });

    T.test("max n, random values (timing check)", [] {
        mt19937 rng(4242);
        vector<int> nums(100000);
        for (int& x : nums) x = (int)(rng() % 100000) + 1;
        return expectEq(Solution().sortableIntegers(nums), 0);
    });

    return T.summary();
}
