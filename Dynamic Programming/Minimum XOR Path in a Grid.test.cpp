// Hidden judge for "Minimum XOR Path in a Grid.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum XOR Path in a Grid.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<vector<int>> grid = {{1, 2}, {3, 4}};
        return expectEq(Solution().minCost(grid), 6);
    });

    T.test("Example 2", [] {
        vector<vector<int>> grid = {{6, 7}, {5, 8}};
        return expectEq(Solution().minCost(grid), 9);
    });

    T.test("Example 3", [] {
        vector<vector<int>> grid = {{2, 7, 5}};
        return expectEq(Solution().minCost(grid), 0);
    });

    T.test("single cell", [] {
        vector<vector<int>> grid = {{7}};
        return expectEq(Solution().minCost(grid), 7);
    });

    T.test("single cell holding zero", [] {
        vector<vector<int>> grid = {{0}};
        return expectEq(Solution().minCost(grid), 0);
    });

    T.test("single column, only one path", [] {
        vector<vector<int>> grid = {{1}, {2}, {3}, {4}};
        return expectEq(Solution().minCost(grid), 4);
    });

    T.test("keeping only the smallest XOR per cell gives the wrong answer", [] {
        vector<vector<int>> grid = {{2, 12}, {11, 12}};
        return expectEq(Solution().minCost(grid), 2);
    });

    T.test("every cell zero", [] {
        vector<vector<int>> grid(4, vector<int>(4, 0));
        return expectEq(Solution().minCost(grid), 0);
    });

    T.test("all cells equal, odd path length", [] {
        vector<vector<int>> grid(3, vector<int>(3, 5));
        return expectEq(Solution().minCost(grid), 5);
    });

    T.test("all cells equal, even path length", [] {
        vector<vector<int>> grid(2, vector<int>(3, 5));
        return expectEq(Solution().minCost(grid), 0);
    });

    T.test("max value in every cell", [] {
        vector<vector<int>> grid(3, vector<int>(3, 1023));
        return expectEq(Solution().minCost(grid), 1023);
    });

    T.test("some path cancels out to zero", [] {
        vector<vector<int>> grid = {{7, 9, 8, 4}, {2, 12, 6, 14}, {10, 4, 3, 0}, {7, 5, 5, 9}};
        return expectEq(Solution().minCost(grid), 0);
    });

    T.test("timing: single row of 1000 cells", [] {
        int n = 1000;
        vector<vector<int>> grid(1, vector<int>(n));
        for (int j = 0; j < n; j++) grid[0][j] = (j * 37 + 11) % 1024;
        return expectEq(Solution().minCost(grid), 72);
    });

    T.test("timing: single column of 1000 cells", [] {
        int m = 1000;
        vector<vector<int>> grid(m, vector<int>(1));
        for (int i = 0; i < m; i++) grid[i][0] = (i * 53 + 7) % 1024;
        return expectEq(Solution().minCost(grid), 248);
    });

    T.test("timing: 20 x 50 grid, every value odd so the answer cannot be 0", [] {
        int m = 20, n = 50;
        vector<vector<int>> grid(m, vector<int>(n));
        mt19937 rng(2718);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) grid[i][j] = (rng() % 512) * 2 + 1;
        return expectEq(Solution().minCost(grid), 1);
    });

    return T.summary();
}
