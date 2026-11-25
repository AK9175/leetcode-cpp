// Hidden judge for "Maximum Subarray With Equal Products.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Maximum Subarray With Equal Products.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1, 2, 1, 2, 1, 1, 1};
        return expectEq(Solution().maxLength(nums), 5);
    });

    T.test("Example 2", [] {
        vector<int> nums = {2, 3, 4, 5, 6};
        return expectEq(Solution().maxLength(nums), 3);
    });

    T.test("Example 3", [] {
        vector<int> nums = {1, 2, 3, 1, 4, 5, 1};
        return expectEq(Solution().maxLength(nums), 5);
    });

    T.test("two ones", [] {
        vector<int> nums = {1, 1};
        return expectEq(Solution().maxLength(nums), 2);
    });

    T.test("two equal non-one values", [] {
        vector<int> nums = {2, 2};
        return expectEq(Solution().maxLength(nums), 2);
    });

    T.test("single non-one values are not product equivalent", [] {
        vector<int> nums = {2, 2, 2};
        return expectEq(Solution().maxLength(nums), 2);
    });

    T.test("two coprime values", [] {
        vector<int> nums = {2, 3};
        return expectEq(Solution().maxLength(nums), 2);
    });

    T.test("all ones", [] {
        vector<int> nums = {1, 1, 1, 1, 1};
        return expectEq(Solution().maxLength(nums), 5);
    });

    T.test("pairwise coprime sequence", [] {
        vector<int> nums = {2, 3, 5, 7};
        return expectEq(Solution().maxLength(nums), 4);
    });

    T.test("best subarray is shorter than the full array", [] {
        vector<int> nums = {2, 6, 3};
        return expectEq(Solution().maxLength(nums), 2);
    });

    T.test("repeated composite values", [] {
        vector<int> nums = {10, 10, 10};
        return expectEq(Solution().maxLength(nums), 2);
    });

    T.test("ones around repeated value", [] {
        vector<int> nums = {1, 2, 2, 1};
        return expectEq(Solution().maxLength(nums), 2);
    });

    T.test("maximum length all ones", [] {
        vector<int> nums(100, 1);
        return expectEq(Solution().maxLength(nums), 100);
    });

    T.test("maximum length all tens", [] {
        vector<int> nums(100, 10);
        return expectEq(Solution().maxLength(nums), 2);
    });

    T.test("smaller all tens", [] {
        vector<int> nums = {10, 10, 10, 10, 10};
        return expectEq(Solution().maxLength(nums), 2);
    });

    T.test("valid trailing subarray", [] {
        vector<int> nums = {2, 9, 4, 3, 1};
        return expectEq(Solution().maxLength(nums), 3);
    });

    return T.summary();
}
