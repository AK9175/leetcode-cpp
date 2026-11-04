// Hidden judge for "Minimum Moves to Equal Array Elements.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Moves to Equal Array Elements.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1, 2, 3};
        return expectEq(Solution().minMoves(nums), 3);
    });

    T.test("Example 2", [] {
        vector<int> nums = {1, 1, 1};
        return expectEq(Solution().minMoves(nums), 0);
    });

    T.test("single element", [] {
        vector<int> nums = {5};
        return expectEq(Solution().minMoves(nums), 0);
    });

    T.test("single element at the lower bound", [] {
        vector<int> nums = {-1000000000};
        return expectEq(Solution().minMoves(nums), 0);
    });

    T.test("two elements", [] {
        vector<int> nums = {1, 100};
        return expectEq(Solution().minMoves(nums), 99);
    });

    T.test("already all equal", [] {
        vector<int> nums = {7, 7, 7, 7};
        return expectEq(Solution().minMoves(nums), 0);
    });

    T.test("all values negative", [] {
        vector<int> nums = {-5, -3, -1};
        return expectEq(Solution().minMoves(nums), 6);
    });

    T.test("mixed signs around zero", [] {
        vector<int> nums = {-1, 0, 1};
        return expectEq(Solution().minMoves(nums), 3);
    });

    T.test("widest possible pair", [] {
        vector<int> nums = {-1000000000, 1000000000};
        return expectEq(Solution().minMoves(nums), 2000000000);
    });

    T.test("descending order", [] {
        vector<int> nums = {10, 5, 1};
        return expectEq(Solution().minMoves(nums), 13);
    });

    T.test("timing: 100000 copies of the maximum value", [] {
        vector<int> nums(100000, 1000000000);
        // Every element is already equal, so the answer is 0 - but the sum is 1e14.
        return expectEq(Solution().minMoves(nums), 0);
    });

    T.test("timing: 100000 copies of the minimum value", [] {
        vector<int> nums(100000, -1000000000);
        return expectEq(Solution().minMoves(nums), 0);
    });

    T.test("timing: 100000 elements, answer just under INT_MAX", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; i++) nums[i] = (i % 2) ? 42948 : 0;
        return expectEq(Solution().minMoves(nums), 2147400000);
    });

    T.test("timing: 100000 random values", [] {
        vector<int> nums(100000);
        mt19937 rng(7);
        for (auto& x : nums) x = (int)(rng() % 20001) - 10000;
        return expectEq(Solution().minMoves(nums), 999351977);
    });

    T.test("timing: 100000 elements packed against the lower bound", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; i++) nums[i] = -1000000000 + (i % 3);
        return expectEq(Solution().minMoves(nums), 99999);
    });

    return T.summary();
}
