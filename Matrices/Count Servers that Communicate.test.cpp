// Hidden judge for "Count Servers that Communicate.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Count Servers that Communicate.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<vector<int>> grid = {{1, 0}, {0, 1}};
        return expectEq(Solution().countServers(grid), 0);
    });

    T.test("Example 2", [] {
        vector<vector<int>> grid = {{1, 0}, {1, 1}};
        return expectEq(Solution().countServers(grid), 3);
    });

    T.test("Example 3", [] {
        vector<vector<int>> grid = {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
        return expectEq(Solution().countServers(grid), 4);
    });

    T.test("single empty cell", [] {
        vector<vector<int>> grid = {{0}};
        return expectEq(Solution().countServers(grid), 0);
    });

    T.test("single cell holding a lone server", [] {
        vector<vector<int>> grid = {{1}};
        return expectEq(Solution().countServers(grid), 0);
    });

    T.test("grid with no servers at all", [] {
        vector<vector<int>> grid = {{0, 0}, {0, 0}};
        return expectEq(Solution().countServers(grid), 0);
    });

    T.test("a single server is never counted", [] {
        vector<vector<int>> grid = {{0, 0}, {0, 1}};
        return expectEq(Solution().countServers(grid), 0);
    });

    T.test("one full row, 1 x n", [] {
        vector<vector<int>> grid = {{1, 1, 1, 1, 1}};
        return expectEq(Solution().countServers(grid), 5);
    });

    T.test("one full column, n x 1", [] {
        vector<vector<int>> grid = {{1}, {1}, {1}, {1}, {1}};
        return expectEq(Solution().countServers(grid), 5);
    });

    T.test("main diagonal, every server isolated", [] {
        vector<vector<int>> grid = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        return expectEq(Solution().countServers(grid), 0);
    });

    T.test("a row of three counts all three", [] {
        vector<vector<int>> grid = {{1, 1, 0, 1}};
        return expectEq(Solution().countServers(grid), 3);
    });

    T.test("plus shape: corners talk, center is isolated", [] {
        vector<vector<int>> grid = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
        return expectEq(Solution().countServers(grid), 4);
    });

    T.test("timing: 250x250 at roughly half density", [] {
        int m = 250, n = 250;
        vector<vector<int>> grid(m, vector<int>(n));
        mt19937 rng(1);
        for (auto& row : grid)
            for (auto& v : row) v = (int)(rng() % 100 < 50);
        return expectEq(Solution().countServers(grid), 31470);
    });

    T.test("timing: 250x250 completely full", [] {
        int m = 250, n = 250;
        vector<vector<int>> grid(m, vector<int>(n, 1));
        return expectEq(Solution().countServers(grid), 62500);
    });

    T.test("timing: 250x250 identity, every server isolated", [] {
        int m = 250, n = 250;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i < 250; i++) grid[i][i] = 1;
        return expectEq(Solution().countServers(grid), 0);
    });

    return T.summary();
}
