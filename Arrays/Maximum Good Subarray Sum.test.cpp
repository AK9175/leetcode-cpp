// Hidden judge for "Maximum Good Subarray Sum.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Maximum Good Subarray Sum.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        int k = 1;
        return expectEq(Solution().maximumSubarraySum(nums, k), 11LL);
    });

    T.test("Example 2", [] {
        vector<int> nums = {-1, 3, 2, 4, 5};
        int k = 3;
        return expectEq(Solution().maximumSubarraySum(nums, k), 11LL);
    });

    T.test("Example 3", [] {
        vector<int> nums = {-1, -2, -3, -4};
        int k = 2;
        return expectEq(Solution().maximumSubarraySum(nums, k), -6LL);
    });

    T.test("shortest array, good", [] {
        vector<int> nums = {1, 2};
        int k = 1;
        return expectEq(Solution().maximumSubarraySum(nums, k), 3LL);
    });

    T.test("shortest array, not good", [] {
        vector<int> nums = {1, 2};
        int k = 5;
        return expectEq(Solution().maximumSubarraySum(nums, k), 0LL);
    });

    T.test("all elements equal, no good subarray", [] {
        vector<int> nums = {7, 7, 7, 7};
        int k = 1;
        return expectEq(Solution().maximumSubarraySum(nums, k), 0LL);
    });

    T.test("k larger than every difference", [] {
        vector<int> nums = {1, 5, 9};
        int k = 100;
        return expectEq(Solution().maximumSubarraySum(nums, k), 0LL);
    });

    T.test("best good subarray has a negative sum", [] {
        vector<int> nums = {3, -50, -50, 4};
        int k = 1;
        return expectEq(Solution().maximumSubarraySum(nums, k), -93LL);
    });

    T.test("farther match beats the nearest one", [] {
        vector<int> nums = {10, -1, -1, 11, 5, 5, 11};
        int k = 1;
        return expectEq(Solution().maximumSubarraySum(nums, k), 40LL);
    });

    T.test("repeated values, the best start is not the last one", [] {
        vector<int> nums = {2, 1, 1, 1, 3, -100, 2, 1};
        int k = 1;
        return expectEq(Solution().maximumSubarraySum(nums, k), 8LL);
    });

    T.test("values on both sides of zero", [] {
        vector<int> nums = {-2, 0, 2, -2, 0};
        int k = 2;
        return expectEq(Solution().maximumSubarraySum(nums, k), 2LL);
    });

    T.test("largest value with the largest k", [] {
        vector<int> nums = {1000000000, 0};
        int k = 1000000000;
        return expectEq(Solution().maximumSubarraySum(nums, k), 1000000000LL);
    });

    T.test("smallest value with the largest k", [] {
        vector<int> nums = {-1000000000, 0};
        int k = 1000000000;
        return expectEq(Solution().maximumSubarraySum(nums, k), -1000000000LL);
    });

    T.test("alternating extremes, difference never equals k", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; ++i) nums[i] = (i % 2 == 0) ? 1000000000 : -1000000000;
        int k = 1;
        return expectEq(Solution().maximumSubarraySum(nums, k), 0LL);
    });

    T.test("max n, sum far beyond 32 bits (timing check)", [] {
        vector<int> nums(100000, 1000000000);
        nums[0] = 999999999;
        int k = 1;
        // Only index 0 pairs with anything, so the best subarray is the whole array.
        return expectEq(Solution().maximumSubarraySum(nums, k), 99999999999999LL);
    });

    T.test("max n, every element near the negative limit (timing check)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; ++i) nums[i] = -1000000000 + (i % 2);
        int k = 1;
        return expectEq(Solution().maximumSubarraySum(nums, k), -1999999999LL);
    });

    T.test("max n, strictly increasing (timing check)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; ++i) nums[i] = i + 1;
        int k = 1;
        return expectEq(Solution().maximumSubarraySum(nums, k), 199999LL);
    });

    T.test("max n, random values from a narrow range (timing check)", [] {
        mt19937 rng(515);
        vector<int> nums(100000);
        for (int& x : nums) x = (int)(rng() % 201) - 100;
        int k = 5;
        return expectEq(Solution().maximumSubarraySum(nums, k), 14978LL);
    });

    return T.summary();
}
