// Hidden judge for "The Celebrity Problem.cpp" (the site doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "The Celebrity Problem.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<vector<int>> mat = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};
        return expectEq(Solution().celebrity(mat), 1);
    });

    T.test("Example 2", [] {
        vector<vector<int>> mat = {{1, 1}, {1, 1}};
        return expectEq(Solution().celebrity(mat), -1);
    });

    T.test("Example 3", [] {
        vector<vector<int>> mat = {{1}};
        return expectEq(Solution().celebrity(mat), 0);
    });

    T.test("two people, the first one is the celebrity", [] {
        vector<vector<int>> mat = {{1, 0}, {1, 1}};
        return expectEq(Solution().celebrity(mat), 0);
    });

    T.test("two people, neither knows the other", [] {
        vector<vector<int>> mat = {{1, 0}, {0, 1}};
        return expectEq(Solution().celebrity(mat), -1);
    });

    T.test("nobody knows anybody", [] {
        int n = 4;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) mat[i][i] = 1;
        return expectEq(Solution().celebrity(mat), -1);
    });

    T.test("everybody knows everybody", [] {
        int n = 4;
        vector<vector<int>> mat(n, vector<int>(n, 1));
        return expectEq(Solution().celebrity(mat), -1);
    });

    T.test("celebrity is person 0", [] {
        int n = 5;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            mat[i][i] = 1;
            if (i != 0) mat[i][0] = 1;
        }
        return expectEq(Solution().celebrity(mat), 0);
    });

    T.test("celebrity is the last person", [] {
        int n = 5;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            mat[i][i] = 1;
            if (i != n - 1) mat[i][n - 1] = 1;
        }
        return expectEq(Solution().celebrity(mat), 4);
    });

    T.test("one person fails to know the candidate", [] {
        vector<vector<int>> mat = {{1, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}};
        return expectEq(Solution().celebrity(mat), -1);
    });

    T.test("the candidate knows one person", [] {
        vector<vector<int>> mat = {{1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}};
        return expectEq(Solution().celebrity(mat), -1);
    });

    T.test("celebrity in the middle, others know each other too", [] {
        int n = 7, c = 3;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            mat[i][i] = 1;
            if (i != c) mat[i][c] = 1;
        }
        mat[0][1] = 1;
        mat[1][2] = 1;
        mat[4][5] = 1;
        mat[6][0] = 1;
        return expectEq(Solution().celebrity(mat), c);
    });

    T.test("timing: 1000 people with a celebrity", [] {
        int n = 1000, c = 617;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            mat[i][i] = 1;
            if (i != c) mat[i][c] = 1;
        }
        mt19937 rng(99);
        for (int k = 0; k < 5000; k++) {
            int a = rng() % n, b = rng() % n;
            if (a != c && a != b) mat[a][b] = 1;
        }
        return expectEq(Solution().celebrity(mat), 617);
    });

    T.test("timing: 1000 people, no celebrity", [] {
        int n = 1000;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        mt19937 rng(123);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) mat[i][j] = (i == j) ? 1 : (int)(rng() % 2);
        return expectEq(Solution().celebrity(mat), -1);
    });

    return T.summary();
}
