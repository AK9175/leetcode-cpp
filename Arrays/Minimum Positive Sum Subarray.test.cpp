// Hidden judge for "Minimum Positive Sum Subarray.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Positive Sum Subarray.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {3, -2, 1, 4};
        int l = 2, r = 3;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), 1);
    });

    T.test("Example 2", [] {
        vector<int> nums = {-2, 2, -3, 1};
        int l = 2, r = 3;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), -1);
    });

    T.test("Example 3", [] {
        vector<int> nums = {1, 2, 3, 4};
        int l = 2, r = 4;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), 3);
    });

    T.test("single positive element", [] {
        vector<int> nums = {5};
        int l = 1, r = 1;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), 5);
    });

    T.test("single negative element has no positive sum", [] {
        vector<int> nums = {-5};
        int l = 1, r = 1;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), -1);
    });

    T.test("a single zero is not greater than zero", [] {
        vector<int> nums = {0};
        int l = 1, r = 1;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), -1);
    });

    T.test("all elements negative", [] {
        vector<int> nums = {-1, -2, -3};
        int l = 1, r = 3;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), -1);
    });

    T.test("all positive, the smallest single element wins", [] {
        vector<int> nums = {4, 1, 3, 2};
        int l = 1, r = 1;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), 1);
    });

    T.test("fixed window length l equals r", [] {
        vector<int> nums = {3, -2, 1, 4};
        int l = 2, r = 2;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), 1);
    });

    T.test("whole array required but its sum is not positive", [] {
        vector<int> nums = {1, -5, 2};
        int l = 3, r = 3;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), -1);
    });

    T.test("only a longer window reaches a positive sum", [] {
        vector<int> nums = {-1, -1, 5};
        int l = 2, r = 3;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), 3);
    });

    T.test("zero-sum windows are excluded", [] {
        vector<int> nums = {2, -2, 3, -3};
        int l = 2, r = 2;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), 1);
    });

    T.test("large magnitudes cancel to a small positive", [] {
        vector<int> nums = {1000, -999, 1000};
        int l = 2, r = 3;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), 1);
    });

    T.test("timing: 100 elements, all window sizes allowed", [] {
        int n = 100;
        vector<int> nums(n);
        mt19937 rng(1);
        for (auto& x : nums) x = (int)(rng() % 2001) - 1000;
        int l = 1, r = 100;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), 3);
    });

    T.test("timing: 100 elements, one lone positive amid big negatives", [] {
        int n = 100;
        vector<int> nums(n, -1000);
        nums[50] = 1;
        int l = 1, r = 100;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), 1);
    });

    T.test("timing: 100 all-negative elements, no answer", [] {
        int n = 100;
        vector<int> nums(n, -1000);
        int l = 1, r = 100;
        return expectEq(Solution().minimumSumSubarray(nums, l, r), -1);
    });

    return T.summary();
}
