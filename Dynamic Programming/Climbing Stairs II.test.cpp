// Hidden judge for "Climbing Stairs II.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Climbing Stairs II.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        int n = 4;
        vector<int> costs = {1, 2, 3, 4};
        return expectEq(Solution().climbStairs(n, costs), 13);
    });

    T.test("Example 2", [] {
        int n = 4;
        vector<int> costs = {5, 1, 6, 2};
        return expectEq(Solution().climbStairs(n, costs), 11);
    });

    T.test("Example 3", [] {
        int n = 3;
        vector<int> costs = {9, 8, 3};
        return expectEq(Solution().climbStairs(n, costs), 12);
    });

    T.test("single step", [] {
        int n = 1;
        vector<int> costs = {5};
        return expectEq(Solution().climbStairs(n, costs), 6);
    });

    T.test("two steps, one jump wins", [] {
        int n = 2;
        vector<int> costs = {3, 7};
        return expectEq(Solution().climbStairs(n, costs), 11);
    });

    T.test("three steps, small jumps beat one big jump", [] {
        int n = 3;
        vector<int> costs = {1, 1, 100};
        return expectEq(Solution().climbStairs(n, costs), 105);
    });

    T.test("all equal costs", [] {
        int n = 5;
        vector<int> costs = {4, 4, 4, 4, 4};
        return expectEq(Solution().climbStairs(n, costs), 21);
    });

    T.test("expensive middle steps are jumped over", [] {
        int n = 4;
        vector<int> costs = {1, 100, 100, 1};
        return expectEq(Solution().climbStairs(n, costs), 12);
    });

    T.test("cheap steps reward single jumps", [] {
        int n = 6;
        vector<int> costs = {1, 1, 1, 1, 1, 1};
        return expectEq(Solution().climbStairs(n, costs), 12);
    });

    T.test("the last step is unavoidable and expensive", [] {
        int n = 4;
        vector<int> costs = {1, 1, 1, 1000};
        return expectEq(Solution().climbStairs(n, costs), 1007);
    });

    T.test("ascending costs", [] {
        int n = 5;
        vector<int> costs = {1, 2, 3, 4, 5};
        return expectEq(Solution().climbStairs(n, costs), 18);
    });

    T.test("descending costs", [] {
        int n = 5;
        vector<int> costs = {5, 4, 3, 2, 1};
        return expectEq(Solution().climbStairs(n, costs), 16);
    });

    T.test("timing: 100000 steps, all minimum cost", [] {
        int n = 100000;
        vector<int> costs(n, 1);
        return expectEq(Solution().climbStairs(n, costs), 200000);
    });

    T.test("timing: 100000 steps, all maximum cost", [] {
        int n = 100000;
        vector<int> costs(n, 10000);
        // Optimal minimises step count with jumps of 3; the answer is ~3.3e8, still in int.
        return expectEq(Solution().climbStairs(n, costs), 333639996);
    });

    T.test("timing: 100000 steps, random costs", [] {
        int n = 100000;
        vector<int> costs(n);
        mt19937 rng(1);
        for (auto& c : costs) c = 1 + (int)(rng() % 10000);
        return expectEq(Solution().climbStairs(n, costs), 116699838);
    });

    return T.summary();
}
