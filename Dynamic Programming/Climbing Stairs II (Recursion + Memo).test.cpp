// Hidden judge for "Climbing Stairs II (Recursion + Memo).cpp".
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
//
// Same problem as "Climbing Stairs II", solved top-down. The recursion goes O(n) deep,
// so the timing tests here use n = 3000 (which the local sanitized stack survives)
// rather than n = 1e5. The iterative version's test file covers the full scale.
#include "Climbing Stairs II (Recursion + Memo).cpp"

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

    T.test("timing: 3000 steps, all minimum cost", [] {
        int n = 3000;
        vector<int> costs(n, 1);
        return expectEq(Solution().climbStairs(n, costs), 6000);
    });

    T.test("timing: 3000 steps, random costs", [] {
        int n = 3000;
        vector<int> costs(n);
        mt19937 rng(1);
        for (auto& c : costs) c = 1 + (int)(rng() % 10000);
        return expectEq(Solution().climbStairs(n, costs), 3572922);
    });

    return T.summary();
}
