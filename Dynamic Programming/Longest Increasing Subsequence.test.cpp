// Hidden judge for "Longest Increasing Subsequence.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Longest Increasing Subsequence.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {10,9,2,5,3,7,101,18};
        return expectEq(Solution().lengthOfLIS(nums), 4);
    });

    T.test("Example 2", [] {
        vector<int> nums = {0,1,0,3,2,3};
        return expectEq(Solution().lengthOfLIS(nums), 4);
    });

    T.test("Example 3", [] {
        vector<int> nums = {7,7,7,7,7,7,7};
        return expectEq(Solution().lengthOfLIS(nums), 1);
    });

    T.test("single element", [] {
        vector<int> nums = {5};
        return expectEq(Solution().lengthOfLIS(nums), 1);
    });

    T.test("two elements, increasing", [] {
        vector<int> nums = {1,2};
        return expectEq(Solution().lengthOfLIS(nums), 2);
    });

    T.test("two elements, equal", [] {
        vector<int> nums = {2,2};
        return expectEq(Solution().lengthOfLIS(nums), 1);
    });

    T.test("strictly decreasing", [] {
        vector<int> nums = {5,4,3,2,1};
        return expectEq(Solution().lengthOfLIS(nums), 1);
    });

    T.test("strictly increasing", [] {
        vector<int> nums = {1,2,3,4,5};
        return expectEq(Solution().lengthOfLIS(nums), 5);
    });

    T.test("duplicates inside a rising run", [] {
        vector<int> nums = {1,1,2,2,3,3};
        return expectEq(Solution().lengthOfLIS(nums), 3);
    });

    T.test("two plateaus only", [] {
        vector<int> nums = {2,2,2,3,3,3};
        return expectEq(Solution().lengthOfLIS(nums), 2);
    });

    T.test("all negative", [] {
        vector<int> nums = {-3,-5,-2,-8,-1};
        return expectEq(Solution().lengthOfLIS(nums), 3);
    });

    T.test("extreme values at both ends", [] {
        vector<int> nums = {-10000,10000,-10000,0,10000};
        return expectEq(Solution().lengthOfLIS(nums), 3);
    });

    T.test("best subsequence abandons the long prefix", [] {
        vector<int> nums = {1,3,6,7,9,4,10,5,6};
        return expectEq(Solution().lengthOfLIS(nums), 6);
    });

    T.test("max n, strictly increasing, largest possible answer (timing check)", [] {
        vector<int> nums(2500);
        for (int i = 0; i < 2500; i++) nums[i] = i - 10000;
        return expectEq(Solution().lengthOfLIS(nums), 2500);
    });

    T.test("max n, strictly decreasing (timing check)", [] {
        vector<int> nums(2500);
        for (int i = 0; i < 2500; i++) nums[i] = 10000 - i;
        return expectEq(Solution().lengthOfLIS(nums), 1);
    });

    T.test("max n, only five distinct values (timing check)", [] {
        vector<int> nums(2500);
        mt19937 rng(11);
        for (int i = 0; i < 2500; i++) nums[i] = (int)(rng() % 5);
        return expectEq(Solution().lengthOfLIS(nums), 5);
    });

    return T.summary();
}
