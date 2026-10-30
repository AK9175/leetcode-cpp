// Hidden judge for "Minimum Swaps to Sort by Digit Sum.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Swaps to Sort by Digit Sum.cpp"

// Input generator for the big tests: the first `count` numbers whose digits add up to 27,
// in increasing order. They all share a digit sum, so the target order is just ascending.
static vector<int> sameDigitSumAscending(int count) {
    vector<int> out;
    for (int x = 1; (int)out.size() < count; ++x) {
        int s = 0;
        for (int y = x; y; y /= 10) s += y % 10;
        if (s == 27) out.push_back(x);
    }
    return out;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {37, 100};
        return expectEq(Solution().minSwaps(nums), 1);
    });

    T.test("Example 2", [] {
        vector<int> nums = {22, 14, 33, 7};
        return expectEq(Solution().minSwaps(nums), 0);
    });

    T.test("Example 3", [] {
        vector<int> nums = {18, 43, 34, 16};
        return expectEq(Solution().minSwaps(nums), 2);
    });

    T.test("Example 2 values, three-cycle out of place", [] {
        vector<int> nums = {33, 14, 7, 22};
        return expectEq(Solution().minSwaps(nums), 2);
    });

    T.test("single element", [] {
        vector<int> nums = {5};
        return expectEq(Solution().minSwaps(nums), 0);
    });

    T.test("two elements already in order", [] {
        vector<int> nums = {1, 2};
        return expectEq(Solution().minSwaps(nums), 0);
    });

    T.test("ascending by value but descending by digit sum", [] {
        vector<int> nums = {19, 20};
        return expectEq(Solution().minSwaps(nums), 1);
    });

    T.test("equal digit sums, ties broken by value", [] {
        vector<int> nums = {100, 10, 1000, 1};
        return expectEq(Solution().minSwaps(nums), 2);
    });

    T.test("equal digit sums, exact reverse of target order", [] {
        vector<int> nums = {1000, 100, 10, 1};
        return expectEq(Solution().minSwaps(nums), 2);
    });

    T.test("equal digit sums, rotated by one", [] {
        vector<int> nums = {10, 100, 1};
        return expectEq(Solution().minSwaps(nums), 2);
    });

    T.test("smallest and largest allowed values together", [] {
        vector<int> nums = {1000000000, 999999999, 1};
        return expectEq(Solution().minSwaps(nums), 2);
    });

    T.test("nine single digits in descending order", [] {
        vector<int> nums = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        return expectEq(Solution().minSwaps(nums), 4);
    });

    T.test("ten mixed values, mostly tied digit sums", [] {
        vector<int> nums = {91, 19, 55, 100, 7, 64, 28, 1000000000, 46, 73};
        return expectEq(Solution().minSwaps(nums), 8);
    });

    T.test("max n, already in target order (timing check)", [] {
        vector<int> nums = sameDigitSumAscending(100000);
        return expectEq(Solution().minSwaps(nums), 0);
    });

    T.test("max n, exact reverse of target order (timing check)", [] {
        vector<int> nums = sameDigitSumAscending(100000);
        reverse(nums.begin(), nums.end());
        // Reversing n elements pairs them up, so it takes n / 2 swaps.
        return expectEq(Solution().minSwaps(nums), 50000);
    });

    T.test("max n, shuffled values 1..100000 (timing check)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; ++i) nums[i] = i + 1;
        mt19937 rng(777);
        shuffle(nums.begin(), nums.end(), rng);
        return expectEq(Solution().minSwaps(nums), 99988);
    });

    return T.summary();
}
