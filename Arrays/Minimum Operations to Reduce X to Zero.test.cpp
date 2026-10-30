// Hidden judge for "Minimum Operations to Reduce X to Zero.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Operations to Reduce X to Zero.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1,1,4,2,3};
        int x = 5;
        return expectEq(Solution().minOperations(nums, x), 2);
    });

    T.test("Example 2", [] {
        vector<int> nums = {5,1,4,2,3};
        int x = 6;
        return expectEq(Solution().minOperations(nums, x), 2);
    });

    T.test("Example 3", [] {
        vector<int> nums = {3,2,20,1,1,3};
        int x = 10;
        return expectEq(Solution().minOperations(nums, x), 5);
    });

    T.test("single element equals x", [] {
        vector<int> nums = {1};
        int x = 1;
        return expectEq(Solution().minOperations(nums, x), 1);
    });

    T.test("single element smaller than x", [] {
        vector<int> nums = {5};
        int x = 3;
        return expectEq(Solution().minOperations(nums, x), -1);
    });

    T.test("x equals the whole array sum", [] {
        vector<int> nums = {1,2,3,4};
        int x = 10;
        return expectEq(Solution().minOperations(nums, x), 4);
    });

    T.test("x exceeds the whole array sum by one", [] {
        vector<int> nums = {1,2,3};
        int x = 7;
        return expectEq(Solution().minOperations(nums, x), -1);
    });

    T.test("answer lies entirely on the left", [] {
        vector<int> nums = {2,3,1,1,1};
        int x = 5;
        return expectEq(Solution().minOperations(nums, x), 2);
    });

    T.test("answer lies entirely on the right", [] {
        vector<int> nums = {1,1,1,3,2};
        int x = 5;
        return expectEq(Solution().minOperations(nums, x), 2);
    });

    T.test("answer needs both ends", [] {
        vector<int> nums = {5,2,3,1,1};
        int x = 6;
        return expectEq(Solution().minOperations(nums, x), 2);
    });

    T.test("all values equal, x not reachable", [] {
        vector<int> nums = {3,3,3};
        int x = 4;
        return expectEq(Solution().minOperations(nums, x), -1);
    });

    T.test("max values at both ends", [] {
        vector<int> nums = {10000,1,1,1,10000};
        int x = 10002;
        return expectEq(Solution().minOperations(nums, x), 3);
    });

    T.test("max n, repeating pattern, one element left over (timing check)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; ++i) nums[i] = (i % 100) + 1;
        int x = 5050000 - 1;  // whole sum minus the smallest value
        return expectEq(Solution().minOperations(nums, x), 99999);
    });

    T.test("max n, all max values, x equals the whole sum (timing check)", [] {
        vector<int> nums(100000, 10000);
        int x = 1000000000;
        return expectEq(Solution().minOperations(nums, x), 100000);
    });

    T.test("max n, all max values, x not reachable (timing check)", [] {
        vector<int> nums(100000, 10000);
        int x = 999999999;
        return expectEq(Solution().minOperations(nums, x), -1);
    });

    return T.summary();
}
