// Hidden judge for "Number of Closed Islands.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Number of Closed Islands.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},
                                    {1,0,0,0,0,1,1,0},
                                    {1,0,1,0,1,1,1,0},
                                    {1,0,0,0,0,1,0,1},
                                    {1,1,1,1,1,1,1,0}};
        return expectEq(Solution().closedIsland(grid), 2);
    });

    T.test("Example 2", [] {
        vector<vector<int>> grid = {{0,0,1,0,0},
                                    {0,1,0,1,0},
                                    {0,1,1,1,0}};
        return expectEq(Solution().closedIsland(grid), 1);
    });

    T.test("Example 3", [] {
        vector<vector<int>> grid = {{1,1,1,1,1,1,1},
                                    {1,0,0,0,0,0,1},
                                    {1,0,1,1,1,0,1},
                                    {1,0,1,0,1,0,1},
                                    {1,0,1,1,1,0,1},
                                    {1,0,0,0,0,0,1},
                                    {1,1,1,1,1,1,1}};
        return expectEq(Solution().closedIsland(grid), 2);
    });

    T.test("single cell, land", [] {
        vector<vector<int>> grid = {{0}};
        return expectEq(Solution().closedIsland(grid), 0);
    });

    T.test("single cell, water", [] {
        vector<vector<int>> grid = {{1}};
        return expectEq(Solution().closedIsland(grid), 0);
    });

    T.test("all water", [] {
        vector<vector<int>> grid = {{1,1,1},
                                    {1,1,1},
                                    {1,1,1}};
        return expectEq(Solution().closedIsland(grid), 0);
    });

    T.test("all land", [] {
        vector<vector<int>> grid = {{0,0,0},
                                    {0,0,0},
                                    {0,0,0}};
        return expectEq(Solution().closedIsland(grid), 0);
    });

    T.test("single row, land between water", [] {
        vector<vector<int>> grid = {{1,0,1}};
        return expectEq(Solution().closedIsland(grid), 0);
    });

    T.test("single column, land between water", [] {
        vector<vector<int>> grid = {{1},{0},{1}};
        return expectEq(Solution().closedIsland(grid), 0);
    });

    T.test("one land cell in the centre", [] {
        vector<vector<int>> grid = {{1,1,1},
                                    {1,0,1},
                                    {1,1,1}};
        return expectEq(Solution().closedIsland(grid), 1);
    });

    T.test("two closed islands split by water", [] {
        vector<vector<int>> grid = {{1,1,1,1,1},
                                    {1,0,1,0,1},
                                    {1,0,1,0,1},
                                    {1,1,1,1,1}};
        return expectEq(Solution().closedIsland(grid), 2);
    });

    T.test("island touching only the left edge", [] {
        vector<vector<int>> grid = {{1,1,1,1},
                                    {0,0,0,1},
                                    {1,1,1,1}};
        return expectEq(Solution().closedIsland(grid), 0);
    });

    T.test("island touching only the bottom edge", [] {
        vector<vector<int>> grid = {{1,1,1},
                                    {1,0,1},
                                    {1,0,1}};
        return expectEq(Solution().closedIsland(grid), 0);
    });

    T.test("ring of land around a water hole", [] {
        vector<vector<int>> grid = {{1,1,1,1,1},
                                    {1,0,0,0,1},
                                    {1,0,1,0,1},
                                    {1,0,0,0,1},
                                    {1,1,1,1,1}};
        return expectEq(Solution().closedIsland(grid), 1);
    });

    T.test("lands touching only diagonally", [] {
        vector<vector<int>> grid = {{1,1,1,1},
                                    {1,0,1,1},
                                    {1,1,0,1},
                                    {1,1,1,1}};
        return expectEq(Solution().closedIsland(grid), 2);
    });

    T.test("max grid, lattice of single-cell islands (timing check)", [] {
        vector<vector<int>> grid(100, vector<int>(100, 1));
        for (int i = 1; i < 100; i += 2)
            for (int j = 1; j < 100; j += 2)
                grid[i][j] = 0;
        return expectEq(Solution().closedIsland(grid), 2401);
    });

    T.test("max grid, one huge island inside a water border (timing check)", [] {
        vector<vector<int>> grid(100, vector<int>(100, 0));
        for (int i = 0; i < 100; i++) {
            grid[i][0] = 1;
            grid[i][99] = 1;
            grid[0][i] = 1;
            grid[99][i] = 1;
        }
        return expectEq(Solution().closedIsland(grid), 1);
    });

    return T.summary();
}
