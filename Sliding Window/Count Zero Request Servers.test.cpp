// Hidden judge for "Count Zero Request Servers.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Count Zero Request Servers.cpp"

// The perf results are 100000-long; compare a {size, sum, first, last} digest instead
// of stringifying the whole vector. The sum exceeds 32 bits, so it is a long long.
static vector<long long> digest(const vector<int>& v) {
    long long sum = 0;
    for (int x : v) sum += x;
    return {(long long)v.size(), sum, v.empty() ? 0 : (long long)v.front(),
            v.empty() ? 0 : (long long)v.back()};
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        int n = 3;
        vector<vector<int>> logs = {{1, 3}, {2, 6}, {1, 5}};
        int x = 5;
        vector<int> queries = {10, 11};
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{1, 2});
    });

    T.test("Example 2", [] {
        int n = 3;
        vector<vector<int>> logs = {{2, 4}, {2, 1}, {1, 2}, {3, 1}};
        int x = 2;
        vector<int> queries = {3, 4};
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{0, 1});
    });

    T.test("single server receives a request in the window", [] {
        int n = 1;
        vector<vector<int>> logs = {{1, 5}};
        int x = 3;
        vector<int> queries = {5, 7};
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{0, 0});
    });

    T.test("single server, request falls outside the window", [] {
        int n = 1;
        vector<vector<int>> logs = {{1, 2}};
        int x = 1;
        vector<int> queries = {5};
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{1});
    });

    T.test("one log answered by several queries", [] {
        int n = 2;
        vector<vector<int>> logs = {{1, 100}};
        int x = 10;
        vector<int> queries = {50, 105, 110, 200};
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{2, 1, 1, 2});
    });

    T.test("duplicate logs for the same server at the same time", [] {
        int n = 3;
        vector<vector<int>> logs = {{1, 5}, {1, 5}, {1, 5}};
        int x = 2;
        vector<int> queries = {6};
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{2});
    });

    T.test("every server busy means zero idle", [] {
        int n = 3;
        vector<vector<int>> logs = {{1, 2}, {2, 2}, {3, 2}};
        int x = 5;
        vector<int> queries = {3};
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{0});
    });

    T.test("no server busy in the window means all idle", [] {
        int n = 3;
        vector<vector<int>> logs = {{1, 1}, {2, 1}};
        int x = 2;
        vector<int> queries = {10};
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{3});
    });

    T.test("request exactly at the left edge counts", [] {
        int n = 2;
        vector<vector<int>> logs = {{1, 5}};
        int x = 3;
        vector<int> queries = {8};  // window [5, 8], time 5 is inside
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{1});
    });

    T.test("request one tick before the left edge is excluded", [] {
        int n = 2;
        vector<vector<int>> logs = {{1, 4}};
        int x = 3;
        vector<int> queries = {8};  // window [5, 8], time 4 is outside
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{2});
    });

    T.test("request one tick after the right edge is excluded", [] {
        int n = 2;
        vector<vector<int>> logs = {{1, 9}};
        int x = 3;
        vector<int> queries = {8};  // window [5, 8], time 9 is outside
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{2});
    });

    T.test("queries given out of time order", [] {
        int n = 3;
        vector<vector<int>> logs = {{1, 3}, {2, 6}, {1, 5}};
        int x = 5;
        vector<int> queries = {11, 10};
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{2, 1});
    });

    T.test("the same query value repeated", [] {
        int n = 3;
        vector<vector<int>> logs = {{1, 3}, {2, 6}};
        int x = 5;
        vector<int> queries = {8, 8, 8};
        return expectEq(Solution().countServers(n, logs, x, queries), vector<int>{1, 1, 1});
    });

    T.test("timing: 100000 of everything, x = 100000", [] {
        int n = 100000, m = 100000, x = 100000, qn = 100000;
        mt19937 rng(1);
        vector<vector<int>> logs;
        for (int i = 0; i < m; i++) logs.push_back({1 + (int)(rng() % n), 1 + (int)(rng() % 1000000)});
        vector<int> queries;
        for (int i = 0; i < qn; i++) queries.push_back(x + 1 + (int)(rng() % (1000000 - x)));
        return expectEq(digest(Solution().countServers(n, logs, x, queries)),
                        vector<long long>{100000, 9047082198LL, 90480, 90553});
    });

    T.test("timing: 100000 of everything, x = 1 (tiny windows)", [] {
        int n = 100000, m = 100000, x = 1, qn = 100000;
        mt19937 rng(2);
        vector<vector<int>> logs;
        for (int i = 0; i < m; i++) logs.push_back({1 + (int)(rng() % n), 1 + (int)(rng() % 1000000)});
        vector<int> queries;
        for (int i = 0; i < qn; i++) queries.push_back(x + 1 + (int)(rng() % (1000000 - x)));
        return expectEq(digest(Solution().countServers(n, logs, x, queries)),
                        vector<long long>{100000, 9999980065LL, 99998, 100000});
    });

    T.test("timing: few servers under heavy traffic", [] {
        int n = 10, m = 100000, x = 500, qn = 100000;
        mt19937 rng(3);
        vector<vector<int>> logs;
        for (int i = 0; i < m; i++) logs.push_back({1 + (int)(rng() % n), 1 + (int)(rng() % 1000000)});
        vector<int> queries;
        for (int i = 0; i < qn; i++) queries.push_back(x + 1 + (int)(rng() % (1000000 - x)));
        return expectEq(digest(Solution().countServers(n, logs, x, queries)),
                        vector<long long>{100000, 6476, 0, 0});
    });

    return T.summary();
}
