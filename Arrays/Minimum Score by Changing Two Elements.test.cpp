// Hidden judge for "Minimum Score by Changing Two Elements.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Score by Changing Two Elements.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1, 4, 7, 8, 5};
        return expectEq(Solution().minimizeSum(nums), 3);
    });

    T.test("Example 2", [] {
        vector<int> nums = {1, 4, 3};
        return expectEq(Solution().minimizeSum(nums), 0);
    });

    T.test("minimum size, all identical", [] {
        vector<int> nums = {5, 5, 5};
        return expectEq(Solution().minimizeSum(nums), 0);
    });

    T.test("minimum size, all distinct collapses to zero", [] {
        vector<int> nums = {1, 100, 50};
        return expectEq(Solution().minimizeSum(nums), 0);
    });

    T.test("four sorted values", [] {
        vector<int> nums = {1, 2, 3, 4};
        return expectEq(Solution().minimizeSum(nums), 1);
    });

    T.test("all equal, larger array", [] {
        vector<int> nums = {7, 7, 7, 7, 7};
        return expectEq(Solution().minimizeSum(nums), 0);
    });

    T.test("one huge outlier is removable", [] {
        vector<int> nums = {1, 1000000000, 2, 3, 4};
        return expectEq(Solution().minimizeSum(nums), 2);
    });

    T.test("duplicates at both ends", [] {
        vector<int> nums = {3, 3, 3, 10, 10};
        return expectEq(Solution().minimizeSum(nums), 0);
    });

    T.test("two low two high, interior pair sets the floor", [] {
        vector<int> nums = {1, 1, 1, 2, 2, 2};
        return expectEq(Solution().minimizeSum(nums), 1);
    });

    T.test("four values with a removable top", [] {
        vector<int> nums = {1, 1, 2, 3};
        return expectEq(Solution().minimizeSum(nums), 0);
    });

    T.test("five mixed values", [] {
        vector<int> nums = {58, 42, 8, 75, 28};
        return expectEq(Solution().minimizeSum(nums), 30);
    });

    T.test("timing: 100000 random values up to 1e9", [] {
        int n = 100000;
        vector<int> nums(n);
        mt19937 rng(1);
        for (auto& x : nums) x = 1 + (int)(rng() % 1000000000);
        return expectEq(Solution().minimizeSum(nums), 999967625);
    });

    T.test("timing: 100000 consecutive 1..n", [] {
        int n = 100000;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = i + 1;
        return expectEq(Solution().minimizeSum(nums), 99997);
    });

    T.test("timing: 100000 with two low values, rest at max", [] {
        int n = 100000;
        vector<int> nums(n, 1000000000);
        nums[0] = 1;
        nums[1] = 2;
        return expectEq(Solution().minimizeSum(nums), 0);
    });

    return T.summary();
}
