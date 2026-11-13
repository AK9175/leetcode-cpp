// Hidden judge for "Count Non-Decreasing Subarrays After K Operations.cpp"
// (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Count Non-Decreasing Subarrays After K Operations.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {6, 3, 1, 2, 4, 4};
        int k = 7;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 17LL);
    });

    T.test("Example 2", [] {
        vector<int> nums = {6, 3, 1, 3, 6};
        int k = 4;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 12LL);
    });

    T.test("single element", [] {
        vector<int> nums = {5};
        int k = 3;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 1LL);
    });

    T.test("two increasing, nothing to fix", [] {
        vector<int> nums = {1, 2};
        int k = 1;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 3LL);
    });

    T.test("two decreasing, enough budget", [] {
        vector<int> nums = {5, 3};
        int k = 2;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 3LL);
    });

    T.test("two decreasing, one short of budget", [] {
        vector<int> nums = {5, 3};
        int k = 1;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 2LL);
    });

    T.test("entirely increasing, every subarray valid", [] {
        vector<int> nums = {1, 2, 3, 4, 5};
        int k = 1;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 15LL);
    });

    T.test("all equal, every subarray already non-decreasing", [] {
        vector<int> nums = {4, 4, 4, 4};
        int k = 1;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 10LL);
    });

    T.test("strictly decreasing, small budget", [] {
        vector<int> nums = {5, 4, 3, 2, 1};
        int k = 1;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 9LL);
    });

    T.test("strictly decreasing, huge budget makes all valid", [] {
        vector<int> nums = {5, 4, 3, 2, 1};
        int k = 1000000000;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 15LL);
    });

    T.test("one tall spike then a long flat tail", [] {
        vector<int> nums = {1, 100, 1, 1, 1};
        int k = 5;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 9LL);
    });

    T.test("huge value, the fix cost overflows 32 bits", [] {
        vector<int> nums = {1000000000, 1, 1, 1};
        int k = 1000000000;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 8LL);
    });

    T.test("peak and valley pattern", [] {
        vector<int> nums = {1, 5, 2, 6, 3};
        int k = 3;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 13LL);
    });

    T.test("alternating small up-down drops", [] {
        vector<int> nums = {3, 1, 2, 5, 4, 8, 6, 10, 9};
        int k = 3;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 37LL);
    });

    T.test("timing: 2000 random values, k = 1e9", [] {
        int n = 2000;
        vector<int> nums(n);
        mt19937 rng(1);
        for (auto& x : nums) x = 1 + (int)(rng() % 1000000000);
        int k = 1000000000;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 9201LL);
    });

    T.test("timing: 2000 small-range values, k = 500", [] {
        int n = 2000;
        vector<int> nums(n);
        mt19937 rng(2);
        for (auto& x : nums) x = 1 + (int)(rng() % 100);
        int k = 500;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 29393LL);
    });

    T.test("timing: 30000 increasing, every subarray valid", [] {
        int n = 30000;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = i + 1;
        int k = 1;
        // all n*(n+1)/2 subarrays are already non-decreasing
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 450015000LL);
    });

    T.test("timing: 30000 decreasing, moderate budget", [] {
        int n = 30000;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = n - i;
        int k = 1000000;
        return expectEq(Solution().countNonDecreasingSubarrays(nums, k), 41421009LL);
    });

    return T.summary();
}
