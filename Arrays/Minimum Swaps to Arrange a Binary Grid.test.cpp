// Hidden judge for "Minimum Swaps to Arrange a Binary Grid.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Swaps to Arrange a Binary Grid.cpp"

// Input generator: the n x n grid whose row i is (i + 1) ones followed by zeros.
// It is already valid, and every row has a different number of trailing zeros.
static vector<vector<int>> staircase(int n) {
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j) g[i][j] = 1;
    return g;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<vector<int>> grid = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};
        return expectEq(Solution().minSwaps(grid), 3);
    });

    T.test("Example 2", [] {
        vector<vector<int>> grid = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}};
        return expectEq(Solution().minSwaps(grid), -1);
    });

    T.test("Example 3", [] {
        vector<vector<int>> grid = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
        return expectEq(Solution().minSwaps(grid), 0);
    });

    T.test("single cell, zero", [] {
        vector<vector<int>> grid = {{0}};
        return expectEq(Solution().minSwaps(grid), 0);
    });

    T.test("single cell, one", [] {
        vector<vector<int>> grid = {{1}};
        return expectEq(Solution().minSwaps(grid), 0);
    });

    T.test("all zeros", [] {
        vector<vector<int>> grid = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
        return expectEq(Solution().minSwaps(grid), 0);
    });

    T.test("all ones, impossible", [] {
        vector<vector<int>> grid = {{1, 1}, {1, 1}};
        return expectEq(Solution().minSwaps(grid), -1);
    });

    T.test("reverse of a valid grid", [] {
        vector<vector<int>> grid = {{1, 1, 1}, {1, 1, 0}, {1, 0, 0}};
        return expectEq(Solution().minSwaps(grid), 3);
    });

    T.test("only the top row blocks the diagonal", [] {
        vector<vector<int>> grid = {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
        return expectEq(Solution().minSwaps(grid), 3);
    });

    T.test("two rows compete for the bottom, impossible", [] {
        vector<vector<int>> grid = {{1, 0, 0}, {0, 0, 1}, {0, 0, 1}};
        return expectEq(Solution().minSwaps(grid), -1);
    });

    T.test("already valid with more zeros than needed", [] {
        vector<vector<int>> grid = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}};
        return expectEq(Solution().minSwaps(grid), 0);
    });

    T.test("several rows could go on top", [] {
        vector<vector<int>> grid = {{1, 1, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 0, 0}};
        return expectEq(Solution().minSwaps(grid), 2);
    });

    T.test("max n, already valid (timing check)", [] {
        vector<vector<int>> grid = staircase(200);
        return expectEq(Solution().minSwaps(grid), 0);
    });

    T.test("max n, reverse of a valid grid (timing check)", [] {
        vector<vector<int>> grid = staircase(200);
        reverse(grid.begin(), grid.end());
        // Each row fits exactly one target position, so the whole order must be undone:
        // n * (n - 1) / 2 adjacent swaps.
        return expectEq(Solution().minSwaps(grid), 19900);
    });

    T.test("max n, every row identical and impossible (timing check)", [] {
        int n = 200;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) grid[i][n - 1] = 1;
        return expectEq(Solution().minSwaps(grid), -1);
    });

    T.test("max n, valid grid with rows shuffled (timing check)", [] {
        vector<vector<int>> grid = staircase(200);
        mt19937 rng(99);
        shuffle(grid.begin(), grid.end(), rng);
        return expectEq(Solution().minSwaps(grid), 9953);
    });

    return T.summary();
}
