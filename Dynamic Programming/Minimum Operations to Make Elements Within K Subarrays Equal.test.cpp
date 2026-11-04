// Hidden judge for "Minimum Operations to Make Elements Within K Subarrays Equal.cpp"
// (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Operations to Make Elements Within K Subarrays Equal.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {5, -2, 1, 3, 7, 3, 6, 4, -1};
        int x = 3;
        int k = 2;
        return expectEq(Solution().minOperations(nums, x, k), 8LL);
    });

    T.test("Example 2", [] {
        vector<int> nums = {9, -2, -2, -2, 1, 5};
        int x = 2;
        int k = 2;
        return expectEq(Solution().minOperations(nums, x, k), 3LL);
    });

    T.test("every element already equal costs nothing", [] {
        vector<int> nums = {4, 4, 4, 4, 4, 4};
        int x = 2;
        int k = 2;
        return expectEq(Solution().minOperations(nums, x, k), 0LL);
    });

    T.test("smallest input, one window", [] {
        vector<int> nums = {1, 5};
        int x = 2;
        int k = 1;
        return expectEq(Solution().minOperations(nums, x, k), 4LL);
    });

    T.test("k * x equals n so the whole array is tiled", [] {
        vector<int> nums = {1, 5, 3, 9};
        int x = 2;
        int k = 2;
        return expectEq(Solution().minOperations(nums, x, k), 10LL);
    });

    T.test("k * x equals n with an odd window", [] {
        vector<int> nums = {5, -2, 1, 3, 7, 3};
        int x = 3;
        int k = 2;
        return expectEq(Solution().minOperations(nums, x, k), 11LL);
    });

    T.test("x equals n, a single whole-array window", [] {
        vector<int> nums = {3, 1, 4, 1, 5};
        int x = 5;
        int k = 1;
        return expectEq(Solution().minOperations(nums, x, k), 7LL);
    });

    T.test("k = 1 picks the single cheapest window", [] {
        vector<int> nums = {0, 0, 9, 0, 0, 9, 0, 0};
        int x = 2;
        int k = 1;
        return expectEq(Solution().minOperations(nums, x, k), 0LL);
    });

    T.test("alternating signs force every window to pay", [] {
        vector<int> nums = {-5, 5, -5, 5, -5, 5};
        int x = 2;
        int k = 3;
        return expectEq(Solution().minOperations(nums, x, k), 30LL);
    });

    T.test("two free blocks chosen over cheaper-looking overlaps", [] {
        vector<int> nums = {7, 7, 100, 3, 3, 3, 200, 8, 8};
        int x = 2;
        int k = 2;
        return expectEq(Solution().minOperations(nums, x, k), 0LL);
    });

    T.test("even-length window, any middle value is optimal", [] {
        vector<int> nums = {1, 2, 3, 4};
        int x = 4;
        int k = 1;
        return expectEq(Solution().minOperations(nums, x, k), 4LL);
    });

    T.test("odd-length window uses the exact median", [] {
        vector<int> nums = {1, 2, 3, 4, 5};
        int x = 5;
        int k = 1;
        return expectEq(Solution().minOperations(nums, x, k), 6LL);
    });

    T.test("extreme magnitudes, cost overflows 32 bits", [] {
        vector<int> nums(30);
        for (int i = 0; i < 30; i++) nums[i] = (i & 1) ? 1000000 : -1000000;
        int x = 2;
        int k = 15;
        return expectEq(Solution().minOperations(nums, x, k), 30000000LL);
    });

    T.test("timing: n = 100000, x = 2, k = 15, random", [] {
        int n = 100000;
        vector<int> nums(n);
        mt19937 rng(1);
        for (auto& v : nums) v = (int)(rng() % 2000001) - 1000000;
        return expectEq(Solution().minOperations(nums, 2, 15), 1386LL);
    });

    T.test("timing: n = 100000, x = 6666, k = 15, random", [] {
        int n = 100000;
        vector<int> nums(n);
        mt19937 rng(2);
        for (auto& v : nums) v = (int)(rng() % 2000001) - 1000000;
        return expectEq(Solution().minOperations(nums, 6666, 15), 50102880630LL);
    });

    T.test("timing: n = 100000, x = 50000, k = 2, random", [] {
        int n = 100000;
        vector<int> nums(n);
        mt19937 rng(5);
        for (auto& v : nums) v = (int)(rng() % 2000001) - 1000000;
        return expectEq(Solution().minOperations(nums, 50000, 2), 49940541617LL);
    });

    T.test("timing: n = 100000, x = 100, k = 10, narrow range", [] {
        int n = 100000;
        vector<int> nums(n);
        mt19937 rng(4);
        for (auto& v : nums) v = (int)(rng() % 2001) - 1000;
        return expectEq(Solution().minOperations(nums, 100, 10), 401709LL);
    });

    return T.summary();
}
