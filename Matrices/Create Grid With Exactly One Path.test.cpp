// Hidden judge for "Create Grid With Exactly One Path.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Create Grid With Exactly One Path.cpp"

// Any grid meeting the statement is accepted, so each test checks properties rather than
// one fixed answer: right shape, only '.' and '#', and exactly one right/down route of
// free cells from (0,0) to (m-1,n-1). Counting routes in a finished grid is verification,
// not a solution. The all-free 25x25 worst case is 32'247'603'683'100 routes, so the
// counter has to be 64-bit.
static bool isValid(int m, int n, const vector<string>& grid) {
    if ((int)grid.size() != m) return false;
    for (const string& row : grid) {
        if ((int)row.size() != n) return false;
        for (char c : row)
            if (c != '.' && c != '#') return false;
    }
    if (grid[0][0] != '.' || grid[m - 1][n - 1] != '.') return false;

    vector<vector<long long>> paths(m, vector<long long>(n, 0));
    paths[0][0] = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') { paths[i][j] = 0; continue; }
            if (i == 0 && j == 0) continue;
            long long total = 0;
            if (i > 0) total += paths[i - 1][j];
            if (j > 0) total += paths[i][j - 1];
            paths[i][j] = total;
        }
    return paths[m - 1][n - 1] == 1;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        int m = 2;
        int n = 3;
        vector<string> got = Solution().createGrid(m, n);
        return expectValid(got, isValid(m, n, got), "exactly one valid path");
    });

    T.test("Example 2", [] {
        int m = 3;
        int n = 3;
        vector<string> got = Solution().createGrid(m, n);
        return expectValid(got, isValid(m, n, got), "exactly one valid path");
    });

    T.test("Example 3", [] {
        int m = 1;
        int n = 4;
        vector<string> got = Solution().createGrid(m, n);
        return expectValid(got, isValid(m, n, got), "exactly one valid path");
    });

    T.test("smallest grid, start is also the finish", [] {
        int m = 1;
        int n = 1;
        vector<string> got = Solution().createGrid(m, n);
        return expectValid(got, isValid(m, n, got), "exactly one valid path");
    });

    T.test("single row, two cells", [] {
        int m = 1;
        int n = 2;
        vector<string> got = Solution().createGrid(m, n);
        return expectValid(got, isValid(m, n, got), "exactly one valid path");
    });

    T.test("single column, two cells", [] {
        int m = 2;
        int n = 1;
        vector<string> got = Solution().createGrid(m, n);
        return expectValid(got, isValid(m, n, got), "exactly one valid path");
    });

    T.test("smallest square with a real choice", [] {
        int m = 2;
        int n = 2;
        vector<string> got = Solution().createGrid(m, n);
        return expectValid(got, isValid(m, n, got), "exactly one valid path");
    });

    T.test("single row at max width", [] {
        int m = 1;
        int n = 25;
        vector<string> got = Solution().createGrid(m, n);
        return expectValid(got, isValid(m, n, got), "exactly one valid path");
    });

    T.test("single column at max height", [] {
        int m = 25;
        int n = 1;
        vector<string> got = Solution().createGrid(m, n);
        return expectValid(got, isValid(m, n, got), "exactly one valid path");
    });

    T.test("wide rectangle, two rows at max width", [] {
        int m = 2;
        int n = 25;
        vector<string> got = Solution().createGrid(m, n);
        return expectValid(got, isValid(m, n, got), "exactly one valid path");
    });

    T.test("tall rectangle, two columns at max height", [] {
        int m = 25;
        int n = 2;
        vector<string> got = Solution().createGrid(m, n);
        return expectValid(got, isValid(m, n, got), "exactly one valid path");
    });

    T.test("max square", [] {
        int m = 25;
        int n = 25;
        vector<string> got = Solution().createGrid(m, n);
        return expectValid(got, isValid(m, n, got), "exactly one valid path");
    });

    T.test("every legal (m, n) from 1 to 25", [] {
        for (int m = 1; m <= 25; m++)
            for (int n = 1; n <= 25; n++) {
                vector<string> got = Solution().createGrid(m, n);
                if (!isValid(m, n, got))
                    return expectValid(got, false,
                                       "exactly one valid path for m=" + to_string(m) +
                                           ", n=" + to_string(n));
            }
        return expectValid(string("all 625 grids"), true, "exactly one valid path");
    });

    return T.summary();
}
