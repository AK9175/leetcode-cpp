// Hidden judge for "Find Two Non-overlapping Sub-arrays Each With Target Sum.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Find Two Non-overlapping Sub-arrays Each With Target Sum.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> arr = {3,2,2,4,3};
        int target = 3;
        return expectEq(Solution().minSumOfLengths(arr, target), 2);
    });

    T.test("Example 2", [] {
        vector<int> arr = {7,3,4,7};
        int target = 7;
        return expectEq(Solution().minSumOfLengths(arr, target), 2);
    });

    T.test("Example 3", [] {
        vector<int> arr = {4,3,2,6,2,3,4};
        int target = 6;
        return expectEq(Solution().minSumOfLengths(arr, target), -1);
    });

    T.test("single element", [] {
        vector<int> arr = {5};
        int target = 5;
        return expectEq(Solution().minSumOfLengths(arr, target), -1);
    });

    T.test("two elements, each equals target", [] {
        vector<int> arr = {5,5};
        int target = 5;
        return expectEq(Solution().minSumOfLengths(arr, target), 2);
    });

    T.test("only the whole array matches", [] {
        vector<int> arr = {1,2,3};
        int target = 6;
        return expectEq(Solution().minSumOfLengths(arr, target), -1);
    });

    T.test("target larger than total sum", [] {
        vector<int> arr = {1,2,3};
        int target = 100;
        return expectEq(Solution().minSumOfLengths(arr, target), -1);
    });

    T.test("two matches that overlap", [] {
        vector<int> arr = {1,6,1};
        int target = 7;
        return expectEq(Solution().minSumOfLengths(arr, target), -1);
    });

    T.test("two shortest matches overlap each other", [] {
        vector<int> arr = {1,1,1,2,1,1,1};
        int target = 3;
        return expectEq(Solution().minSumOfLengths(arr, target), 5);
    });

    T.test("best pair at both ends", [] {
        vector<int> arr = {4,1,1,1,1,1,1,4};
        int target = 4;
        return expectEq(Solution().minSumOfLengths(arr, target), 2);
    });

    T.test("random small values, n = 40", [] {
        mt19937 rng(1477);
        vector<int> arr(40);
        for (int& x : arr) x = rng() % 4 + 1;
        int target = 7;
        return expectEq(Solution().minSumOfLengths(arr, target), 4);
    });

    T.test("max n, all 1000, target 1000", [] {
        vector<int> arr(100000, 1000);
        int target = 1000;
        return expectEq(Solution().minSumOfLengths(arr, target), 2);
    });

    T.test("max n, all ones, halves match exactly", [] {
        vector<int> arr(100000, 1);
        int target = 50000;
        return expectEq(Solution().minSumOfLengths(arr, target), 100000);
    });

    T.test("max n, all ones, target just over half", [] {
        vector<int> arr(100000, 1);
        int target = 50001;
        return expectEq(Solution().minSumOfLengths(arr, target), -1);
    });

    T.test("max n, all 1000, target 1e8 (whole array)", [] {
        vector<int> arr(100000, 1000);
        int target = 100000000;
        return expectEq(Solution().minSumOfLengths(arr, target), -1);
    });

    return T.summary();
}
