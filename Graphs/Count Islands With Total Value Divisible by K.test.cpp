// Hidden judge for "Count Islands With Total Value Divisible by K.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Count Islands With Total Value Divisible by K.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<vector<int>> grid = {{0, 2, 1, 0, 0},
                                    {0, 5, 0, 0, 5},
                                    {0, 0, 1, 0, 0},
                                    {0, 1, 4, 7, 0},
                                    {0, 2, 0, 0, 8}};
        int k = 5;
        return expectEq(Solution().countIslands(grid, k), 2);
    });

    T.test("Example 2", [] {
        vector<vector<int>> grid = {{3, 0, 3, 0}, {0, 3, 0, 3}, {3, 0, 3, 0}};
        int k = 3;
        return expectEq(Solution().countIslands(grid, k), 6);
    });

    T.test("all water, no islands", [] {
        vector<vector<int>> grid = {{0, 0, 0}, {0, 0, 0}};
        int k = 7;
        return expectEq(Solution().countIslands(grid, k), 0);
    });

    T.test("1x1 land, divisible", [] {
        vector<vector<int>> grid = {{6}};
        int k = 3;
        return expectEq(Solution().countIslands(grid, k), 1);
    });

    T.test("1x1 land, not divisible", [] {
        vector<vector<int>> grid = {{7}};
        int k = 3;
        return expectEq(Solution().countIslands(grid, k), 0);
    });

    T.test("1x1 water", [] {
        vector<vector<int>> grid = {{0}};
        int k = 1;
        return expectEq(Solution().countIslands(grid, k), 0);
    });

    T.test("k = 1, every island counts", [] {
        vector<vector<int>> grid = {{1, 0, 2}, {0, 0, 0}, {3, 0, 4}};
        int k = 1;
        return expectEq(Solution().countIslands(grid, k), 4);
    });

    T.test("single row split by water", [] {
        vector<vector<int>> grid = {{1, 2, 0, 4, 0, 5, 5}};
        int k = 3;
        return expectEq(Solution().countIslands(grid, k), 1);
    });

    T.test("single column split by water", [] {
        vector<vector<int>> grid = {{2}, {4}, {0}, {9}, {0}, {1}};
        int k = 6;
        return expectEq(Solution().countIslands(grid, k), 1);
    });

    T.test("whole grid is one island, not divisible", [] {
        vector<vector<int>> grid = {{1, 1, 1}, {1, 1, 1}};
        int k = 5;
        return expectEq(Solution().countIslands(grid, k), 0);
    });

    T.test("island total exceeds 32-bit int", [] {
        vector<vector<int>> grid(50, vector<int>(50, 1000000));  // total 2'500'000'000
        int k = 1000000;
        return expectEq(Solution().countIslands(grid, k), 1);
    });

    T.test("max cells, one all-land island (timing check)", [] {
        vector<vector<int>> grid(1000, vector<int>(100, 1000000));  // total 10^11
        int k = 1000000;
        return expectEq(Solution().countIslands(grid, k), 1);
    });

    T.test("max cells, checkerboard of single-cell islands (timing check)", [] {
        vector<vector<int>> grid(200, vector<int>(500, 0));
        for (int i = 0; i < 200; i++)
            for (int j = 0; j < 500; j++)
                if ((i + j) % 2 == 0) grid[i][j] = 2;
        int k = 2;
        return expectEq(Solution().countIslands(grid, k), 50000);
    });

    T.test("max cells, snake-shaped single island (timing check)", [] {
        int m = 1000, n = 100;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < n; j++) grid[i][j] = 1;
            } else {
                grid[i][(i / 2) % 2 == 0 ? n - 1 : 0] = 1;  // bend joining two rows
            }
        }
        int k = 50500;  // the snake covers exactly 50500 cells of value 1
        return expectEq(Solution().countIslands(grid, k), 1);
    });

    return T.summary();
}
