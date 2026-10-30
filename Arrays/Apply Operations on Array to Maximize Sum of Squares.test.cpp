// Hidden judge for "Apply Operations on Array to Maximize Sum of Squares.cpp"
// (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Apply Operations on Array to Maximize Sum of Squares.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {2,6,5,8};
        int k = 2;
        return expectEq(Solution().maxSum(nums, k), 261);
    });

    T.test("Example 2", [] {
        vector<int> nums = {4,5,4,7};
        int k = 3;
        return expectEq(Solution().maxSum(nums, k), 90);
    });

    T.test("k equals n, the extra picks are zeros", [] {
        vector<int> nums = {2,6,5,8};
        int k = 4;
        return expectEq(Solution().maxSum(nums, k), 261);
    });

    T.test("k equals 1, only the best element counts", [] {
        vector<int> nums = {2,6,5,8};
        int k = 1;
        return expectEq(Solution().maxSum(nums, k), 225);
    });

    T.test("single element", [] {
        vector<int> nums = {5};
        int k = 1;
        return expectEq(Solution().maxSum(nums, k), 25);
    });

    T.test("all equal, k below n", [] {
        vector<int> nums = {3,3,3};
        int k = 2;
        return expectEq(Solution().maxSum(nums, k), 18);
    });

    T.test("all ones", [] {
        vector<int> nums = {1,1,1,1};
        int k = 3;
        return expectEq(Solution().maxSum(nums, k), 3);
    });

    T.test("disjoint bits merge into one element", [] {
        vector<int> nums = {1,2,4,8};
        int k = 1;
        return expectEq(Solution().maxSum(nums, k), 225);
    });

    T.test("disjoint bits, k beyond the merged element", [] {
        vector<int> nums = {1,2,4,8};
        int k = 2;
        return expectEq(Solution().maxSum(nums, k), 225);
    });

    T.test("identical values share no movable bits", [] {
        vector<int> nums = {7,7,7};
        int k = 3;
        return expectEq(Solution().maxSum(nums, k), 147);
    });

    T.test("max element value, modulo already bites", [] {
        vector<int> nums = {1000000000};
        int k = 1;
        return expectEq(Solution().maxSum(nums, k), 49);
    });

    T.test("largest constructible value from single bits", [] {
        vector<int> nums(30);
        for (int b = 0; b < 30; b++) nums[b] = 1 << b;   // OR of all = 2^30 - 1
        int k = 1;
        return expectEq(Solution().maxSum(nums, k), 388912871);
    });

    T.test("max n, every element 1e9 (timing check)", [] {
        vector<int> nums(100000, 1000000000);
        int k = 100000;
        return expectEq(Solution().maxSum(nums, k), 4900000);
    });

    T.test("max n, random values, all picked (timing check)", [] {
        vector<int> nums(100000);
        mt19937 rng(2026);
        for (int i = 0; i < 100000; i++) nums[i] = 1 + rng() % 1000000000;
        int k = 100000;
        return expectEq(Solution().maxSum(nums, k), 800306876);
    });

    T.test("max n, random values, one pick (timing check)", [] {
        vector<int> nums(100000);
        mt19937 rng(2026);
        for (int i = 0; i < 100000; i++) nums[i] = 1 + rng() % 1000000000;
        int k = 1;
        return expectEq(Solution().maxSum(nums, k), 388912871);
    });

    T.test("max n, every element 1 (timing check)", [] {
        vector<int> nums(100000, 1);
        int k = 100000;
        return expectEq(Solution().maxSum(nums, k), 100000);
    });

    return T.summary();
}
