// Hidden judge for "Twisted Mirror Path Count.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Twisted Mirror Path Count.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<vector<int>> grid = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
        return expectEq(Solution().uniquePaths(grid), 5);
    });

    T.test("Example 2", [] {
        vector<vector<int>> grid = {{0, 0}, {0, 0}};
        return expectEq(Solution().uniquePaths(grid), 2);
    });

    T.test("Example 3", [] {
        vector<vector<int>> grid = {{0, 1, 1}, {1, 1, 0}};
        return expectEq(Solution().uniquePaths(grid), 1);
    });

    T.test("smallest grid with no valid path", [] {
        vector<vector<int>> grid = {{0, 1, 0, 0}, {0, 0, 1, 0}};
        return expectEq(Solution().uniquePaths(grid), 0);
    });

    T.test("2x2 mirrors on the anti-diagonal", [] {
        vector<vector<int>> grid = {{0, 1}, {1, 0}};
        return expectEq(Solution().uniquePaths(grid), 2);
    });

    T.test("3x3 with no mirrors", [] {
        vector<vector<int>> grid(3, vector<int>(3, 0));
        return expectEq(Solution().uniquePaths(grid), 6);
    });

    T.test("3x3 with a single mirror in the centre", [] {
        vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        return expectEq(Solution().uniquePaths(grid), 4);
    });

    T.test("3x3 mirrors everywhere but the two corners", [] {
        vector<vector<int>> grid = {{0, 1, 1}, {1, 1, 1}, {1, 1, 0}};
        return expectEq(Solution().uniquePaths(grid), 2);
    });

    T.test("top row is all mirrors", [] {
        vector<vector<int>> grid = {{0, 1, 1, 1, 0}, {0, 0, 0, 0, 0}};
        return expectEq(Solution().uniquePaths(grid), 2);
    });

    T.test("left column is all mirrors", [] {
        vector<vector<int>> grid = {{0, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 0}};
        return expectEq(Solution().uniquePaths(grid), 2);
    });

    T.test("10x10 with no mirrors", [] {
        vector<vector<int>> grid(10, vector<int>(10, 0));
        return expectEq(Solution().uniquePaths(grid), 48620);
    });

    T.test("40x40 with no mirrors, answer needs the modulo", [] {
        vector<vector<int>> grid(40, vector<int>(40, 0));
        return expectEq(Solution().uniquePaths(grid), 929264847);
    });

    T.test("500 rows but only 2 columns", [] {
        vector<vector<int>> grid(500, vector<int>(2, 0));
        return expectEq(Solution().uniquePaths(grid), 500);
    });

    T.test("6x7 staircase chain landing exactly on the goal", [] {
        vector<vector<int>> grid = {{0, 1, 0, 0, 0, 0, 0},
                                    {0, 1, 1, 0, 0, 0, 0},
                                    {0, 0, 1, 1, 0, 0, 0},
                                    {0, 0, 0, 1, 1, 0, 0},
                                    {0, 0, 0, 0, 1, 1, 0},
                                    {0, 0, 0, 0, 0, 1, 0}};
        return expectEq(Solution().uniquePaths(grid), 1);
    });

    T.test("6x7 with no mirrors", [] {
        vector<vector<int>> grid(6, vector<int>(7, 0));
        return expectEq(Solution().uniquePaths(grid), 462);
    });

    T.test("6x7 mirrors on the superdiagonal", [] {
        vector<vector<int>> grid = {{0, 1, 0, 0, 0, 0, 0},
                                    {0, 0, 1, 0, 0, 0, 0},
                                    {0, 0, 0, 1, 0, 0, 0},
                                    {0, 0, 0, 0, 1, 0, 0},
                                    {0, 0, 0, 0, 0, 1, 0},
                                    {0, 0, 0, 0, 0, 0, 0}};
        return expectEq(Solution().uniquePaths(grid), 132);
    });

    T.test("6x7 vertical wall of mirrors with one gap", [] {
        vector<vector<int>> grid = {{0, 0, 0, 1, 0, 0, 0},
                                    {0, 0, 0, 1, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 1, 0, 0, 0},
                                    {0, 0, 0, 1, 0, 0, 0},
                                    {0, 0, 0, 1, 0, 0, 0}};
        return expectEq(Solution().uniquePaths(grid), 204);
    });

    T.test("6x7 bottom row and right column mirrored", [] {
        vector<vector<int>> grid = {{0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 1},
                                    {0, 0, 0, 0, 0, 0, 1},
                                    {0, 0, 0, 0, 0, 0, 1},
                                    {0, 0, 0, 0, 0, 0, 1},
                                    {0, 1, 1, 1, 1, 1, 0}};
        return expectEq(Solution().uniquePaths(grid), 252);
    });

    T.test("6x7 dense scattered mirrors", [] {
        vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 1},
                                    {0, 1, 0, 1, 1, 0, 0},
                                    {1, 0, 1, 1, 0, 0, 1},
                                    {0, 0, 0, 1, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0},
                                    {1, 0, 0, 0, 1, 0, 0}};
        return expectEq(Solution().uniquePaths(grid), 62);
    });

    T.test("timing: 500x500 with no mirrors", [] {
        vector<vector<int>> grid(500, vector<int>(500, 0));
        // No mirrors means the count is C(m+n-2, m-1) = C(998, 499) mod 1e9+7.
        return expectEq(Solution().uniquePaths(grid), 264223182);
    });

    T.test("timing: 500x500, a quarter mirrors", [] {
        int m = 500, n = 500;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        mt19937 rng(21);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) grid[i][j] = (int)(rng() % 100 < 25);
        grid[0][0] = 0;
        grid[m - 1][n - 1] = 0;
        return expectEq(Solution().uniquePaths(grid), 891562094);
    });

    T.test("timing: 500x500, mostly mirrors", [] {
        int m = 500, n = 500;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        mt19937 rng(22);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) grid[i][j] = (int)(rng() % 100 < 70);
        grid[0][0] = 0;
        grid[m - 1][n - 1] = 0;
        return expectEq(Solution().uniquePaths(grid), 233400987);
    });

    return T.summary();
}
