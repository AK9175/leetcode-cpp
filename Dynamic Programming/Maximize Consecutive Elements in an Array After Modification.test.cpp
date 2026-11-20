// Hidden judge for "Maximize Consecutive Elements in an Array After Modification.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Maximize Consecutive Elements in an Array After Modification.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {2, 1, 5, 1, 1};
        return expectEq(Solution().maxSelectedElements(nums), 3);
    });

    T.test("Example 2", [] {
        vector<int> nums = {1, 4, 7, 10};
        return expectEq(Solution().maxSelectedElements(nums), 1);
    });

    T.test("single element", [] {
        vector<int> nums = {5};
        return expectEq(Solution().maxSelectedElements(nums), 1);
    });

    T.test("two equal values bridge via +1", [] {
        vector<int> nums = {3, 3};
        return expectEq(Solution().maxSelectedElements(nums), 2);
    });

    T.test("all identical", [] {
        vector<int> nums = {7, 7, 7, 7};
        return expectEq(Solution().maxSelectedElements(nums), 2);
    });

    T.test("already consecutive", [] {
        vector<int> nums = {1, 2, 3, 4, 5};
        return expectEq(Solution().maxSelectedElements(nums), 5);
    });

    T.test("gaps of two cannot be bridged", [] {
        vector<int> nums = {1, 3, 5};
        return expectEq(Solution().maxSelectedElements(nums), 2);
    });

    T.test("duplicate pairs form a long chain", [] {
        vector<int> nums = {1, 1, 2, 2, 3, 3};
        return expectEq(Solution().maxSelectedElements(nums), 4);
    });

    T.test("at the max value boundary", [] {
        vector<int> nums = {1000000, 1000000};
        return expectEq(Solution().maxSelectedElements(nums), 2);
    });

    T.test("timing: 100000 consecutive 1..n", [] {
        int n = 100000;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = i + 1;
        return expectEq(Solution().maxSelectedElements(nums), 100000);
    });

    T.test("timing: 100000 all ones", [] {
        vector<int> nums(100000, 1);
        return expectEq(Solution().maxSelectedElements(nums), 2);
    });

    T.test("timing: 100000 duplicate pairs 1,1,2,2,...", [] {
        int n = 100000;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = (i / 2) + 1;
        return expectEq(Solution().maxSelectedElements(nums), 50001);
    });

    T.test("timing: 100000 random values up to 1e6", [] {
        int n = 100000;
        vector<int> nums(n);
        mt19937 rng(2);
        for (auto& x : nums) x = 1 + (int)(rng() % 1000000);
        return expectEq(Solution().maxSelectedElements(nums), 6);
    });

    return T.summary();
}
