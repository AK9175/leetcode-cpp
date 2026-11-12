// Hidden judge for "Longest Strictly Increasing or Strictly Decreasing Subarray.cpp"
// (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Longest Strictly Increasing or Strictly Decreasing Subarray.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1, 4, 3, 3, 2};
        return expectEq(Solution().longestMonotonicSubarray(nums), 2);
    });

    T.test("Example 2", [] {
        vector<int> nums = {3, 3, 3, 3};
        return expectEq(Solution().longestMonotonicSubarray(nums), 1);
    });

    T.test("Example 3", [] {
        vector<int> nums = {3, 2, 1};
        return expectEq(Solution().longestMonotonicSubarray(nums), 3);
    });

    T.test("single element", [] {
        vector<int> nums = {7};
        return expectEq(Solution().longestMonotonicSubarray(nums), 1);
    });

    T.test("two equal elements", [] {
        vector<int> nums = {5, 5};
        return expectEq(Solution().longestMonotonicSubarray(nums), 1);
    });

    T.test("entirely strictly increasing", [] {
        vector<int> nums = {1, 2, 3, 4, 5};
        return expectEq(Solution().longestMonotonicSubarray(nums), 5);
    });

    T.test("entirely strictly decreasing", [] {
        vector<int> nums = {5, 4, 3, 2, 1};
        return expectEq(Solution().longestMonotonicSubarray(nums), 5);
    });

    T.test("increase up to a peak then decrease", [] {
        vector<int> nums = {1, 3, 5, 4, 2};
        return expectEq(Solution().longestMonotonicSubarray(nums), 3);
    });

    T.test("decrease to a valley then increase", [] {
        vector<int> nums = {5, 3, 1, 2, 4};
        return expectEq(Solution().longestMonotonicSubarray(nums), 3);
    });

    T.test("a plateau breaks the run", [] {
        vector<int> nums = {1, 2, 2, 3, 4};
        return expectEq(Solution().longestMonotonicSubarray(nums), 3);
    });

    T.test("alternating up and down", [] {
        vector<int> nums = {1, 2, 1, 2, 1};
        return expectEq(Solution().longestMonotonicSubarray(nums), 2);
    });

    T.test("longest run is at the end", [] {
        vector<int> nums = {5, 5, 1, 2, 3, 4};
        return expectEq(Solution().longestMonotonicSubarray(nums), 4);
    });

    T.test("max length, fully increasing", [] {
        int n = 50;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = i + 1;
        return expectEq(Solution().longestMonotonicSubarray(nums), 50);
    });

    T.test("max length, all equal", [] {
        int n = 50;
        vector<int> nums(n, 25);
        return expectEq(Solution().longestMonotonicSubarray(nums), 1);
    });

    return T.summary();
}
