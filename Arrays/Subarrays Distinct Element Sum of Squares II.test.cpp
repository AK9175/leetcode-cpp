// Hidden judge for "Subarrays Distinct Element Sum of Squares II.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Subarrays Distinct Element Sum of Squares II.cpp"

static const long long MOD = 1'000'000'007;

// Answer when all n values are distinct: every subarray's distinct count is its length,
// so the total is sum over L of (n - L + 1) * L^2.
static int allDistinctAnswer(int n) {
    long long total = 0;
    for (long long L = 1; L <= n; ++L)
        total = (total + (n - L + 1) % MOD * (L * L % MOD)) % MOD;
    return (int)total;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1, 2, 1};
        return expectEq(Solution().sumCounts(nums), 15);
    });

    T.test("Example 2", [] {
        vector<int> nums = {2, 2};
        return expectEq(Solution().sumCounts(nums), 3);
    });

    T.test("single element", [] {
        vector<int> nums = {1};
        return expectEq(Solution().sumCounts(nums), 1);
    });

    T.test("two different elements", [] {
        vector<int> nums = {1, 2};
        return expectEq(Solution().sumCounts(nums), 6);
    });

    T.test("four elements, all distinct", [] {
        vector<int> nums = {1, 2, 3, 4};
        return expectEq(Solution().sumCounts(nums), 50);
    });

    T.test("five elements, all equal", [] {
        vector<int> nums = {2, 2, 2, 2, 2};
        return expectEq(Solution().sumCounts(nums), 15);
    });

    T.test("values at the max allowed value", [] {
        vector<int> nums = {100000, 1, 100000};
        return expectEq(Solution().sumCounts(nums), 15);
    });

    T.test("alternating between two values", [] {
        vector<int> nums = {1, 2, 1, 2, 1, 2};
        return expectEq(Solution().sumCounts(nums), 66);
    });

    T.test("strictly decreasing", [] {
        vector<int> nums = {5, 4, 3, 2, 1};
        return expectEq(Solution().sumCounts(nums), 105);
    });

    T.test("two blocks of repeated values", [] {
        vector<int> nums = {1, 1, 1, 2, 2, 2};
        return expectEq(Solution().sumCounts(nums), 48);
    });

    T.test("only the last element is new", [] {
        vector<int> nums = {3, 3, 3, 3, 7};
        return expectEq(Solution().sumCounts(nums), 27);
    });

    T.test("repeats interleaved with new values", [] {
        vector<int> nums = {1, 2, 3, 1, 2, 4};
        return expectEq(Solution().sumCounts(nums), 137);
    });

    T.test("period-7 pattern, n = 300", [] {
        vector<int> nums(300);
        for (int i = 0; i < 300; ++i) nums[i] = i % 7 + 1;
        return expectEq(Solution().sumCounts(nums), 2151835);
    });

    T.test("n = 2000, all distinct, answer wraps the modulo", [] {
        vector<int> nums(2000);
        for (int i = 0; i < 2000; ++i) nums[i] = i + 1;
        return expectEq(Solution().sumCounts(nums), 1657648);
    });

    T.test("max n, all distinct (timing check)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; ++i) nums[i] = i + 1;
        return expectEq(Solution().sumCounts(nums), allDistinctAnswer(100000));
    });

    T.test("max n, all equal (timing check)", [] {
        int n = 100000;
        vector<int> nums(n, 77777);
        long long expected = (long long)n * (n + 1) / 2 % MOD;
        return expectEq(Solution().sumCounts(nums), (int)expected);
    });

    T.test("max n, alternating two values (timing check)", [] {
        int n = 100000;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = i % 2 + 1;
        // Length-1 subarrays contribute 1 each; every longer subarray contributes 2^2.
        long long longer = ((long long)n * (n + 1) / 2 - n) % MOD;
        long long expected = (n + 4 * longer) % MOD;
        return expectEq(Solution().sumCounts(nums), (int)expected);
    });

    T.test("max n, random values (timing check)", [] {
        mt19937 rng(12345);
        vector<int> nums(100000);
        for (int& x : nums) x = (int)(rng() % 100000) + 1;
        Solution().sumCounts(nums);
        return noCheck();
    });

    return T.summary();
}
