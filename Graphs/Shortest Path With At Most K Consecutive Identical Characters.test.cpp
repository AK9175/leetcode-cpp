// Hidden judge for "Shortest Path With At Most K Consecutive Identical Characters.cpp"
// (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Shortest Path With At Most K Consecutive Identical Characters.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        int n = 3;
        vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}};
        string labels = "aab";
        int k = 1;
        return expectEq(Solution().shortestPath(n, edges, labels, k), 3);
    });

    T.test("Example 2", [] {
        int n = 3;
        vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}};
        string labels = "aab";
        int k = 2;
        return expectEq(Solution().shortestPath(n, edges, labels, k), 2);
    });

    T.test("Example 3", [] {
        int n = 3;
        vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}};
        string labels = "aaa";
        int k = 2;
        return expectEq(Solution().shortestPath(n, edges, labels, k), -1);
    });

    T.test("single node, no edges", [] {
        int n = 1;
        vector<vector<int>> edges = {};
        string labels = "a";
        int k = 1;
        return expectEq(Solution().shortestPath(n, edges, labels, k), 0);
    });

    T.test("two nodes, no edges", [] {
        int n = 2;
        vector<vector<int>> edges = {};
        string labels = "ab";
        int k = 1;
        return expectEq(Solution().shortestPath(n, edges, labels, k), -1);
    });

    T.test("the only edge violates k", [] {
        int n = 2;
        vector<vector<int>> edges = {{0, 1, 1}};
        string labels = "aa";
        int k = 1;
        return expectEq(Solution().shortestPath(n, edges, labels, k), -1);
    });

    T.test("edge points the wrong way", [] {
        int n = 2;
        vector<vector<int>> edges = {{1, 0, 1}};
        string labels = "ab";
        int k = 1;
        return expectEq(Solution().shortestPath(n, edges, labels, k), -1);
    });

    T.test("duplicate edges between the same pair", [] {
        int n = 2;
        vector<vector<int>> edges = {{0, 1, 5}, {0, 1, 2}};
        string labels = "ab";
        int k = 1;
        return expectEq(Solution().shortestPath(n, edges, labels, k), 2);
    });

    T.test("k large enough to ignore the limit", [] {
        int n = 4;
        vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}};
        string labels = "aaaa";
        int k = 50;
        return expectEq(Solution().shortestPath(n, edges, labels, k), 6);
    });

    T.test("run length exactly equals k", [] {
        int n = 4;
        vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}};
        string labels = "aaaa";
        int k = 4;
        return expectEq(Solution().shortestPath(n, edges, labels, k), 3);
    });

    T.test("run length one over k", [] {
        int n = 4;
        vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}};
        string labels = "aaaa";
        int k = 3;
        return expectEq(Solution().shortestPath(n, edges, labels, k), -1);
    });

    T.test("every node the same letter, k = 1", [] {
        int n = 5;
        vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {3, 4, 1}};
        string labels = "aaaaa";
        int k = 1;
        return expectEq(Solution().shortestPath(n, edges, labels, k), -1);
    });

    T.test("detour to break up a run, visiting a node twice", [] {
        int n = 4;
        vector<vector<int>> edges = {{0, 1, 1}, {1, 3, 1}, {1, 2, 1}, {2, 1, 1}};
        string labels = "aaba";
        int k = 2;
        return expectEq(Solution().shortestPath(n, edges, labels, k), 4);
    });

    T.test("timing: 50000-node chain, only two labels", [] {
        int n = 50000;
        vector<vector<int>> edges;
        mt19937 rng(8);
        for (int i = 1; i < n; i++) edges.push_back({i - 1, i, 1 + (int)(rng() % 10000)});
        string labels;
        for (int i = 0; i < n; i++) labels += char('a' + rng() % 2);
        int k = 50;
        return expectEq(Solution().shortestPath(n, edges, labels, k), 250031558);
    });

    T.test("timing: 50000 nodes, target has no incoming edge", [] {
        int n = 50000;
        vector<vector<int>> edges;
        mt19937 rng(11);
        for (int i = 0; i < n; i++) {
            int u = rng() % (n - 1), v = rng() % (n - 1);
            if (u == v) continue;
            edges.push_back({u, v, 1 + (int)(rng() % 10000)});
        }
        string labels;
        for (int i = 0; i < n; i++) labels += char('a' + rng() % 2);
        int k = 50;
        return expectEq(Solution().shortestPath(n, edges, labels, k), -1);
    });

    T.test("timing: 25000-node backbone with random shortcuts", [] {
        int n = 25000;
        vector<vector<int>> edges;
        mt19937 rng(13);
        for (int i = 1; i < n; i++) edges.push_back({i - 1, i, 1});
        for (int i = 0; i < n; i++) {
            int u = rng() % n, v = rng() % n;
            if (u == v) continue;
            edges.push_back({u, v, 1 + (int)(rng() % 100)});
        }
        string labels;
        for (int i = 0; i < n; i++) labels += char('a' + rng() % 2);
        int k = 50;
        return expectEq(Solution().shortestPath(n, edges, labels, k), 70);
    });

    return T.summary();
}
