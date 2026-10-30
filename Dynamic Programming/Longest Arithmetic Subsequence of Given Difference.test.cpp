// Hidden judge for "Longest Arithmetic Subsequence of Given Difference.cpp"
// (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Longest Arithmetic Subsequence of Given Difference.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> arr = {1,2,3,4};
        int difference = 1;
        return expectEq(Solution().longestSubsequence(arr, difference), 4);
    });

    T.test("Example 2", [] {
        vector<int> arr = {1,3,5,7};
        int difference = 1;
        return expectEq(Solution().longestSubsequence(arr, difference), 1);
    });

    T.test("Example 3", [] {
        vector<int> arr = {1,5,7,8,5,3,4,2,1};
        int difference = -2;
        return expectEq(Solution().longestSubsequence(arr, difference), 4);
    });

    T.test("single element, non-zero difference", [] {
        vector<int> arr = {5};
        int difference = 3;
        return expectEq(Solution().longestSubsequence(arr, difference), 1);
    });

    T.test("single element, zero difference", [] {
        vector<int> arr = {5};
        int difference = 0;
        return expectEq(Solution().longestSubsequence(arr, difference), 1);
    });

    T.test("zero difference counts repeats", [] {
        vector<int> arr = {1,1,1,2};
        int difference = 0;
        return expectEq(Solution().longestSubsequence(arr, difference), 3);
    });

    T.test("zero difference, all distinct", [] {
        vector<int> arr = {1,2,3};
        int difference = 0;
        return expectEq(Solution().longestSubsequence(arr, difference), 1);
    });

    T.test("negative difference, descending array", [] {
        vector<int> arr = {5,4,3,2,1};
        int difference = -1;
        return expectEq(Solution().longestSubsequence(arr, difference), 5);
    });

    T.test("chain skips intervening elements", [] {
        vector<int> arr = {1,9,2,9,3};
        int difference = 1;
        return expectEq(Solution().longestSubsequence(arr, difference), 3);
    });

    T.test("duplicates with a non-zero difference", [] {
        vector<int> arr = {1,1,2,2,3,3};
        int difference = 1;
        return expectEq(Solution().longestSubsequence(arr, difference), 3);
    });

    T.test("difference too large for any pair", [] {
        vector<int> arr = {1,2,3};
        int difference = 5;
        return expectEq(Solution().longestSubsequence(arr, difference), 1);
    });

    T.test("right values, wrong order", [] {
        vector<int> arr = {3,2,1};
        int difference = 1;
        return expectEq(Solution().longestSubsequence(arr, difference), 1);
    });

    T.test("extreme values, lookup above the value range", [] {
        vector<int> arr = {10000,0,-10000};
        int difference = -10000;
        return expectEq(Solution().longestSubsequence(arr, difference), 3);
    });

    T.test("extreme values, lookup below the value range", [] {
        vector<int> arr = {-10000,0,10000};
        int difference = 10000;
        return expectEq(Solution().longestSubsequence(arr, difference), 3);
    });

    T.test("max n, all equal with zero difference, largest possible answer (timing check)", [] {
        vector<int> arr(100000, 10000);
        int difference = 0;
        return expectEq(Solution().longestSubsequence(arr, difference), 100000);
    });

    T.test("max n, full value ramp repeated (timing check)", [] {
        vector<int> arr(100000);
        for (int i = 0; i < 100000; i++) arr[i] = -10000 + (i % 20001);
        int difference = 1;
        return expectEq(Solution().longestSubsequence(arr, difference), 20001);
    });

    T.test("max n, many distinct values (timing check)", [] {
        vector<int> arr(100000);
        mt19937 rng(13);
        for (int i = 0; i < 100000; i++) arr[i] = (int)(rng() % 20001) - 10000;
        int difference = 1;
        return expectEq(Solution().longestSubsequence(arr, difference), 16);
    });

    return T.summary();
}
