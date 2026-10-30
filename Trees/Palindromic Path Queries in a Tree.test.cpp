// Hidden judge for "Palindromic Path Queries in a Tree.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Palindromic Path Queries in a Tree.cpp"

// The timing tests return ~25000 booleans, which is unreadable as a literal. This
// compresses an answer into {size, number of trues, positional hash} so a wrong answer
// in any position still changes the expectation.
static vector<long long> digest(const vector<bool>& a) {
    long long trues = 0, h = 0;
    for (bool b : a) {
        trues += b;
        h = (h * 2 + (b ? 1 : 0)) % 1000000007LL;
    }
    return {(long long)a.size(), trues, h};
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        int n = 3;
        vector<vector<int>> edges = {{0, 1}, {1, 2}};
        string s = "aac";
        vector<string> queries = {"query 0 2", "update 1 b", "query 0 2"};
        return expectEq(Solution().palindromePath(n, edges, s, queries), vector<bool>{true, false});
    });

    T.test("Example 2", [] {
        int n = 4;
        vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}};
        string s = "abca";
        vector<string> queries = {"query 1 2", "update 0 b", "query 2 3", "update 3 a", "query 1 3"};
        return expectEq(Solution().palindromePath(n, edges, s, queries),
                        vector<bool>{false, false, true});
    });

    T.test("single node tree", [] {
        int n = 1;
        vector<vector<int>> edges = {};
        string s = "a";
        vector<string> queries = {"query 0 0"};
        return expectEq(Solution().palindromePath(n, edges, s, queries), vector<bool>{true});
    });

    T.test("node queried against itself", [] {
        int n = 3;
        vector<vector<int>> edges = {{0, 1}, {1, 2}};
        string s = "abc";
        vector<string> queries = {"query 1 1"};
        return expectEq(Solution().palindromePath(n, edges, s, queries), vector<bool>{true});
    });

    T.test("only updates, nothing to answer", [] {
        int n = 3;
        vector<vector<int>> edges = {{0, 1}, {1, 2}};
        string s = "abc";
        vector<string> queries = {"update 0 z", "update 1 z"};
        return expectEq(Solution().palindromePath(n, edges, s, queries), vector<bool>{});
    });

    T.test("update to the character already there", [] {
        int n = 3;
        vector<vector<int>> edges = {{0, 1}, {1, 2}};
        string s = "aba";
        vector<string> queries = {"query 0 2", "update 1 b", "query 0 2"};
        return expectEq(Solution().palindromePath(n, edges, s, queries), vector<bool>{true, true});
    });

    T.test("two nodes, letters differ", [] {
        int n = 2;
        vector<vector<int>> edges = {{0, 1}};
        string s = "ab";
        vector<string> queries = {"query 0 1"};
        return expectEq(Solution().palindromePath(n, edges, s, queries), vector<bool>{false});
    });

    T.test("two nodes, same letter", [] {
        int n = 2;
        vector<vector<int>> edges = {{0, 1}};
        string s = "aa";
        vector<string> queries = {"query 0 1"};
        return expectEq(Solution().palindromePath(n, edges, s, queries), vector<bool>{true});
    });

    T.test("every node carries the same letter", [] {
        int n = 5;
        vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
        string s = "zzzzz";
        vector<string> queries = {"query 0 4", "query 0 3", "query 2 2"};
        return expectEq(Solution().palindromePath(n, edges, s, queries),
                        vector<bool>{true, true, true});
    });

    T.test("one endpoint is an ancestor of the other", [] {
        int n = 6;
        vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
        string s = "aabbcc";
        vector<string> queries = {"query 0 5", "query 1 4", "query 0 1"};
        return expectEq(Solution().palindromePath(n, edges, s, queries),
                        vector<bool>{true, false, true});
    });

    T.test("star graph, path through the centre", [] {
        int n = 5;
        vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}};
        string s = "abcde";
        vector<string> queries = {"query 1 2", "query 1 1", "query 3 4"};
        return expectEq(Solution().palindromePath(n, edges, s, queries),
                        vector<bool>{false, true, false});
    });

    T.test("an update flips a false query to true", [] {
        int n = 3;
        vector<vector<int>> edges = {{0, 1}, {1, 2}};
        string s = "abc";
        vector<string> queries = {"query 0 2", "update 2 a", "query 0 2"};
        return expectEq(Solution().palindromePath(n, edges, s, queries), vector<bool>{false, true});
    });

    T.test("all 26 letters on one path", [] {
        int n = 26;
        vector<vector<int>> edges;
        for (int i = 1; i < n; i++) edges.push_back({i - 1, i});
        string s = "abcdefghijklmnopqrstuvwxyz";
        vector<string> queries = {"query 0 25", "query 7 7", "query 0 1"};
        return expectEq(Solution().palindromePath(n, edges, s, queries),
                        vector<bool>{false, true, false});
    });

    T.test("timing: 50000-node path graph, 50000 mixed queries", [] {
        int n = 50000;
        vector<vector<int>> edges;
        for (int i = 1; i < n; i++) edges.push_back({i - 1, i});
        mt19937 rng(1);
        string s;
        for (int i = 0; i < n; i++) s += char('a' + rng() % 2);
        vector<string> queries;
        for (int k = 0; k < 50000; k++) {
            if (rng() % 2)
                queries.push_back("update " + to_string(rng() % n) + " " +
                                  string(1, char('a' + rng() % 2)));
            else
                queries.push_back("query " + to_string(rng() % n) + " " + to_string(rng() % n));
        }
        return expectEq(digest(Solution().palindromePath(n, edges, s, queries)),
                        vector<long long>{25282, 18896, 616008889});
    });

    T.test("timing: 50000-node star graph, 50000 mixed queries", [] {
        int n = 50000;
        vector<vector<int>> edges;
        for (int i = 1; i < n; i++) edges.push_back({0, i});
        mt19937 rng(2);
        string s;
        for (int i = 0; i < n; i++) s += char('a' + rng() % 4);
        vector<string> queries;
        for (int k = 0; k < 50000; k++) {
            if (rng() % 2)
                queries.push_back("update " + to_string(rng() % n) + " " +
                                  string(1, char('a' + rng() % 4)));
            else
                queries.push_back("query " + to_string(rng() % n) + " " + to_string(rng() % n));
        }
        return expectEq(digest(Solution().palindromePath(n, edges, s, queries)),
                        vector<long long>{25047, 15723, 439819931});
    });

    T.test("timing: 50000-node random tree, 50000 mixed queries", [] {
        int n = 50000;
        mt19937 rng(3);
        vector<vector<int>> edges;
        for (int v = 1; v < n; v++) edges.push_back({(int)(rng() % v), v});
        string s;
        for (int i = 0; i < n; i++) s += char('a' + rng() % 2);
        vector<string> queries;
        for (int k = 0; k < 50000; k++) {
            if (rng() % 2)
                queries.push_back("update " + to_string(rng() % n) + " " +
                                  string(1, char('a' + rng() % 2)));
            else
                queries.push_back("query " + to_string(rng() % n) + " " + to_string(rng() % n));
        }
        return expectEq(digest(Solution().palindromePath(n, edges, s, queries)),
                        vector<long long>{25040, 18783, 935122786});
    });

    return T.summary();
}
