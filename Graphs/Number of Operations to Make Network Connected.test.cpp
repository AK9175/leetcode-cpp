// Hidden judge for "Number of Operations to Make Network Connected.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Number of Operations to Make Network Connected.cpp"

int main() {
    TestRunner T(3);

    T.test("Example 1", [] {
        int n = 4;
        vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
        return expectEq(Solution().makeConnected(n, connections), 1);
    });

    T.test("Example 2", [] {
        int n = 6;
        vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
        return expectEq(Solution().makeConnected(n, connections), 2);
    });

    T.test("Example 3", [] {
        int n = 6;
        vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2}};
        return expectEq(Solution().makeConnected(n, connections), -1);
    });

    T.test("two computers, one cable", [] {
        int n = 2;
        vector<vector<int>> connections = {{0,1}};
        return expectEq(Solution().makeConnected(n, connections), 0);
    });

    T.test("already connected chain, no spare cables", [] {
        int n = 5;
        vector<vector<int>> connections = {{3,4},{0,1},{2,3},{1,2}};
        return expectEq(Solution().makeConnected(n, connections), 0);
    });

    T.test("already connected with spare cables", [] {
        int n = 4;
        vector<vector<int>> connections = {{0,1},{1,2},{2,3},{3,0},{0,2}};
        return expectEq(Solution().makeConnected(n, connections), 0);
    });

    T.test("exactly n-1 cables, two groups", [] {
        int n = 5;
        vector<vector<int>> connections = {{0,1},{1,2},{2,0},{3,4}};
        return expectEq(Solution().makeConnected(n, connections), 1);
    });

    T.test("dense group plus isolated computers", [] {
        int n = 6;
        vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
        return expectEq(Solution().makeConnected(n, connections), 2);
    });

    T.test("one cable short despite a loop", [] {
        int n = 5;
        vector<vector<int>> connections = {{0,1},{1,2},{2,0}};
        return expectEq(Solution().makeConnected(n, connections), -1);
    });

    T.test("separate pairs, too few cables", [] {
        int n = 6;
        vector<vector<int>> connections = {{0,1},{2,3},{4,5}};
        return expectEq(Solution().makeConnected(n, connections), -1);
    });

    T.test("many isolated computers, single cable", [] {
        int n = 5;
        vector<vector<int>> connections = {{3,1}};
        return expectEq(Solution().makeConnected(n, connections), -1);
    });

    T.test("highest-numbered computer isolated", [] {
        int n = 4;
        vector<vector<int>> connections = {{0,1},{1,2},{0,2}};
        return expectEq(Solution().makeConnected(n, connections), 1);
    });

    T.test("max n, reversed chain", [] {
        int n = 100000;
        vector<vector<int>> connections;
        for (int i = n - 1; i >= 1; i--) connections.push_back({i, i - 1});
        return expectEq(Solution().makeConnected(n, connections), 0);
    });

    T.test("max n, 1e5 cables packed into 450 computers", [] {
        int n = 100000;
        vector<vector<int>> connections;
        for (int a = 0; a < 450 && (int)connections.size() < 100000; a++)
            for (int b = a + 1; b < 450 && (int)connections.size() < 100000; b++)
                connections.push_back({a, b});
        return expectEq(Solution().makeConnected(n, connections), 99550);
    });

    T.test("max n, random cables (timing check)", [] {
        int n = 100000;
        vector<vector<int>> connections;
        mt19937 rng(1319);
        set<pair<int,int>> seen;
        while ((int)connections.size() < 100000) {
            int a = rng() % n, b = rng() % n;
            if (a == b || seen.count({min(a, b), max(a, b)})) continue;
            seen.insert({min(a, b), max(a, b)});
            connections.push_back({a, b});
        }
        Solution().makeConnected(n, connections);
        return noCheck();
    });

    return T.summary();
}
