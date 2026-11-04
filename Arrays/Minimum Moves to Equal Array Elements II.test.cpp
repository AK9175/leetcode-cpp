// Hidden judge for "Minimum Moves to Equal Array Elements II.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Moves to Equal Array Elements II.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1, 2, 3};
        return expectEq(Solution().minMoves2(nums), 2);
    });

    T.test("Example 2", [] {
        vector<int> nums = {1, 10, 2, 9};
        return expectEq(Solution().minMoves2(nums), 16);
    });

    T.test("single element", [] {
        vector<int> nums = {5};
        return expectEq(Solution().minMoves2(nums), 0);
    });

    T.test("single element at the lower bound", [] {
        vector<int> nums = {-1000000000};
        return expectEq(Solution().minMoves2(nums), 0);
    });

    T.test("two elements", [] {
        vector<int> nums = {1, 100};
        return expectEq(Solution().minMoves2(nums), 99);
    });

    T.test("already all equal", [] {
        vector<int> nums = {7, 7, 7, 7};
        return expectEq(Solution().minMoves2(nums), 0);
    });

    T.test("all values negative", [] {
        vector<int> nums = {-5, -3, -1};
        return expectEq(Solution().minMoves2(nums), 4);
    });

    T.test("mixed signs around zero", [] {
        vector<int> nums = {-1, 0, 1};
        return expectEq(Solution().minMoves2(nums), 2);
    });

    T.test("widest possible pair", [] {
        vector<int> nums = {-1000000000, 1000000000};
        return expectEq(Solution().minMoves2(nums), 2000000000);
    });

    T.test("descending order", [] {
        vector<int> nums = {10, 5, 1};
        return expectEq(Solution().minMoves2(nums), 9);
    });

    T.test("aiming at the average gives the wrong answer", [] {
        vector<int> nums = {1, 1, 1, 100};
        return expectEq(Solution().minMoves2(nums), 99);
    });

    T.test("even length with the two middles far apart", [] {
        vector<int> nums = {1, 2, 100, 101};
        return expectEq(Solution().minMoves2(nums), 198);
    });

    T.test("one huge outlier", [] {
        vector<int> nums = {0, 0, 0, 0, 1000000};
        return expectEq(Solution().minMoves2(nums), 1000000);
    });

    T.test("unsorted three elements", [] {
        vector<int> nums = {2, 3, 1};
        return expectEq(Solution().minMoves2(nums), 2);
    });

    T.test("same array as problem 453, where the answer was 18", [] {
        vector<int> nums = {2, 2, 4, 4, 6, 6, 8};
        // Aiming at the minimum gives 18, aiming at the mean gives 13.
        return expectEq(Solution().minMoves2(nums), 12);
    });

    T.test("timing: 100000 copies of the maximum value", [] {
        vector<int> nums(100000, 1000000000);
        return expectEq(Solution().minMoves2(nums), 0);
    });

    T.test("timing: 100000 elements, answer just under INT_MAX", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; i++) nums[i] = (i < 50000) ? 0 : 42948;
        return expectEq(Solution().minMoves2(nums), 2147400000);
    });

    T.test("timing: 100000 random values", [] {
        vector<int> nums(100000);
        mt19937 rng(11);
        for (auto& x : nums) x = (int)(rng() % 40001) - 20000;
        return expectEq(Solution().minMoves2(nums), 1003836681);
    });

    T.test("timing: 100000 already sorted ascending", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; i++) nums[i] = i / 2;
        return expectEq(Solution().minMoves2(nums), 1250000000);
    });

    T.test("timing: 99999 elements, odd length", [] {
        vector<int> nums(99999);
        mt19937 rng(12);
        for (auto& x : nums) x = (int)(rng() % 21) - 10;
        return expectEq(Solution().minMoves2(nums), 522452);
    });

    return T.summary();
}
