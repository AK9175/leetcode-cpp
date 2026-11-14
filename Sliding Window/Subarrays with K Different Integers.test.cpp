// Hidden judge for "Subarrays with K Different Integers.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Subarrays with K Different Integers.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1, 2, 1, 2, 3};
        int k = 2;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 7);
    });

    T.test("Example 2", [] {
        vector<int> nums = {1, 2, 1, 3, 4};
        int k = 3;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 3);
    });

    T.test("single element, k = 1", [] {
        vector<int> nums = {5};
        int k = 1;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 1);
    });

    T.test("all identical, k = 1 counts every subarray", [] {
        vector<int> nums = {7, 7, 7, 7};
        int k = 1;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 10);
    });

    T.test("all identical, k = 2 has none", [] {
        vector<int> nums = {7, 7, 7, 7};
        int k = 2;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 0);
    });

    T.test("all distinct, k = 1 counts single elements", [] {
        vector<int> nums = {1, 2, 3, 4};
        int k = 1;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 4);
    });

    T.test("all distinct, k = n is the whole array only", [] {
        vector<int> nums = {1, 2, 3, 4};
        int k = 4;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 1);
    });

    T.test("all distinct, k = 2", [] {
        vector<int> nums = {1, 2, 3, 4};
        int k = 2;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 3);
    });

    T.test("alternating two values, k = 2", [] {
        vector<int> nums = {1, 2, 1, 2, 1, 2};
        int k = 2;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 15);
    });

    T.test("k larger than the number of distinct values", [] {
        vector<int> nums = {1, 1, 2, 2};
        int k = 3;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 0);
    });

    T.test("blocks of repeats, k = 2", [] {
        vector<int> nums = {1, 1, 2, 2, 3, 3};
        int k = 2;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 8);
    });

    T.test("k equals the total distinct count", [] {
        vector<int> nums = {1, 2, 3, 2, 1};
        int k = 3;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 5);
    });

    T.test("timing: 20000 with 50 distinct values, k = 25", [] {
        int n = 20000;
        vector<int> nums(n);
        mt19937 rng(1);
        for (auto& x : nums) x = 1 + (int)(rng() % 50);
        int k = 25;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 40349);
    });

    T.test("timing: 20000 with 2 values, k = 2 (answer near n^2/2)", [] {
        int n = 20000;
        vector<int> nums(n);
        mt19937 rng(2);
        for (auto& x : nums) x = 1 + (int)(rng() % 2);
        int k = 2;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 199970129);
    });

    T.test("timing: 20000 all identical, k = 1 is n*(n+1)/2", [] {
        int n = 20000;
        vector<int> nums(n, 7);
        int k = 1;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 200010000);
    });

    T.test("timing: 20000 distinct permutation, k = n is one subarray", [] {
        int n = 20000;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = i + 1;
        int k = n;
        return expectEq(Solution().subarraysWithKDistinct(nums, k), 1);
    });

    return T.summary();
}
