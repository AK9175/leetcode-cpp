// Hidden judge for "Check if There Is a Valid Parentheses String Path.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Check if There Is a Valid Parentheses String Path.cpp"

// An m x n grid whose cell (i, j) is '(' when i + j < split, else ')'. Every monotone path
// through it spells the same string, which makes the expected answer of the big tests plain.
vector<vector<char>> diagonalGrid(int m, int n, int split) {
    vector<vector<char>> g(m, vector<char>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) g[i][j] = (i + j < split) ? '(' : ')';
    return g;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<vector<char>> grid = {{'(','(','('},
                                     {')','(',')'},
                                     {'(','(',')'},
                                     {'(','(',')'}};
        return expectEq(Solution().hasValidPath(grid), true);
    });

    T.test("Example 2", [] {
        vector<vector<char>> grid = {{')',')'},
                                     {'(','('}};
        return expectEq(Solution().hasValidPath(grid), false);
    });

    T.test("single cell, open bracket", [] {
        vector<vector<char>> grid = {{'('}};
        return expectEq(Solution().hasValidPath(grid), false);
    });

    T.test("single cell, close bracket", [] {
        vector<vector<char>> grid = {{')'}};
        return expectEq(Solution().hasValidPath(grid), false);
    });

    T.test("smallest valid grid, one row", [] {
        vector<vector<char>> grid = {{'(',')'}};
        return expectEq(Solution().hasValidPath(grid), true);
    });

    T.test("smallest valid grid, one column", [] {
        vector<vector<char>> grid = {{'('},
                                     {')'}};
        return expectEq(Solution().hasValidPath(grid), true);
    });

    T.test("first cell is a close bracket", [] {
        vector<vector<char>> grid = {{')','(','('},
                                     {')','(',')'},
                                     {'(','(',')'},
                                     {'(','(',')'}};
        return expectEq(Solution().hasValidPath(grid), false);
    });

    T.test("last cell is an open bracket", [] {
        vector<vector<char>> grid = {{'(','(','('},
                                     {')','(',')'},
                                     {'(','(',')'},
                                     {'(','(','('}};
        return expectEq(Solution().hasValidPath(grid), false);
    });

    T.test("every cell is an open bracket", [] {
        vector<vector<char>> grid = {{'(','(','('},
                                     {'(','(','('},
                                     {'(','(','('},
                                     {'(','(','('}};
        return expectEq(Solution().hasValidPath(grid), false);
    });

    T.test("every cell is a close bracket", [] {
        vector<vector<char>> grid = {{')',')',')'},
                                     {')',')',')'},
                                     {')',')',')'},
                                     {')',')',')'}};
        return expectEq(Solution().hasValidPath(grid), false);
    });

    T.test("one row, the only path is valid", [] {
        vector<vector<char>> grid = {{'(','(',')','(',')',')'}};
        return expectEq(Solution().hasValidPath(grid), true);
    });

    T.test("one row, the only path opens with a close bracket", [] {
        vector<vector<char>> grid = {{')','(',')','(',')','('}};
        return expectEq(Solution().hasValidPath(grid), false);
    });

    T.test("one column, the only path is valid", [] {
        vector<vector<char>> grid = {{'('},{'('},{'('},{')'},{')'},{')'}};
        return expectEq(Solution().hasValidPath(grid), true);
    });

    T.test("exactly one of the ten paths is valid", [] {
        vector<vector<char>> grid = {{'(','(',')','('},
                                     {')',')',')',')'},
                                     {')',')',')',')'}};
        return expectEq(Solution().hasValidPath(grid), true);
    });

    T.test("right endpoints but no path is valid", [] {
        vector<vector<char>> grid = {{'(',')',')',')'},
                                     {')',')',')',')'},
                                     {')',')',')',')'}};
        return expectEq(Solution().hasValidPath(grid), false);
    });

    T.test("odd number of cells on every path", [] {
        vector<vector<char>> grid = {{'(','(',')'},
                                     {'(',')','('},
                                     {'(',')',')'}};
        return expectEq(Solution().hasValidPath(grid), false);
    });

    T.test("max size, open half then close half (timing)", [] {
        vector<vector<char>> grid = diagonalGrid(100, 99, 99);
        return expectEq(Solution().hasValidPath(grid), true);
    });

    T.test("max size, one open bracket too few (timing)", [] {
        vector<vector<char>> grid = diagonalGrid(100, 99, 98);
        return expectEq(Solution().hasValidPath(grid), false);
    });

    T.test("max size square, odd number of cells per path (timing)", [] {
        vector<vector<char>> grid = diagonalGrid(100, 100, 100);
        return expectEq(Solution().hasValidPath(grid), false);
    });

    T.test("max size, random brackets, fixed seed (timing)", [] {
        mt19937 rng(12345);
        vector<vector<char>> grid(99, vector<char>(100));
        for (auto& row : grid)
            for (char& c : row) c = (rng() & 1) ? '(' : ')';
        grid[0][0] = '(';
        grid[98][99] = ')';
        return expectEq(Solution().hasValidPath(grid), true);
    });

    return T.summary();
}
