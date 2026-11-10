// Hidden judge for "Find Servers That Handled Most Number of Requests.cpp"
// (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Find Servers That Handled Most Number of Requests.cpp"

int main() {
    TestRunner T;

    // The IDs may be returned in any order, so compare as an unordered multiset.

    T.test("Example 1", [] {
        int k = 3;
        vector<int> arrival = {1, 2, 3, 4, 5};
        vector<int> load = {5, 2, 3, 3, 3};
        return expectAnyOrder(Solution().busiestServers(k, arrival, load), vector<int>{1});
    });

    T.test("Example 2", [] {
        int k = 3;
        vector<int> arrival = {1, 2, 3, 4};
        vector<int> load = {1, 2, 1, 2};
        return expectAnyOrder(Solution().busiestServers(k, arrival, load), vector<int>{0});
    });

    T.test("Example 3", [] {
        int k = 3;
        vector<int> arrival = {1, 2, 3};
        vector<int> load = {10, 12, 11};
        return expectAnyOrder(Solution().busiestServers(k, arrival, load), vector<int>{0, 1, 2});
    });

    T.test("single server handles everything", [] {
        int k = 1;
        vector<int> arrival = {1, 2, 3};
        vector<int> load = {5, 5, 5};
        return expectAnyOrder(Solution().busiestServers(k, arrival, load), vector<int>{0});
    });

    T.test("one request, server 0 wins", [] {
        int k = 3;
        vector<int> arrival = {1};
        vector<int> load = {5};
        return expectAnyOrder(Solution().busiestServers(k, arrival, load), vector<int>{0});
    });

    T.test("everything after the first round is dropped", [] {
        int k = 2;
        vector<int> arrival = {1, 2, 3, 4};
        vector<int> load = {100, 100, 100, 100};
        return expectAnyOrder(Solution().busiestServers(k, arrival, load), vector<int>{0, 1});
    });

    T.test("each request finishes before the next arrives", [] {
        int k = 3;
        vector<int> arrival = {1, 10, 20, 30};
        vector<int> load = {1, 1, 1, 1};
        return expectAnyOrder(Solution().busiestServers(k, arrival, load), vector<int>{0});
    });

    T.test("every server handles one, all tie", [] {
        int k = 4;
        vector<int> arrival = {1, 2, 3, 4};
        vector<int> load = {100, 100, 100, 100};
        return expectAnyOrder(Solution().busiestServers(k, arrival, load), vector<int>{0, 1, 2, 3});
    });

    T.test("large arrival and load values", [] {
        int k = 2;
        vector<int> arrival = {1000000000, 1000000001};
        vector<int> load = {1000000000, 1000000000};
        return expectAnyOrder(Solution().busiestServers(k, arrival, load), vector<int>{0, 1});
    });

    T.test("wrap to server 1 then drop the rest", [] {
        int k = 2;
        vector<int> arrival = {1, 2, 3};
        vector<int> load = {10, 10, 1};
        return expectAnyOrder(Solution().busiestServers(k, arrival, load), vector<int>{0, 1});
    });

    T.test("timing: k=1000, 100000 requests, 6 busiest", [] {
        int k = 1000, n = 100000;
        vector<int> arrival(n), load(n);
        mt19937 rng(1);
        long long t = 0;
        for (int i = 0; i < n; i++) {
            t += 1 + rng() % 3;
            arrival[i] = (int)t;
            load[i] = 1 + (int)(rng() % 5000);
        }
        return expectAnyOrder(Solution().busiestServers(k, arrival, load),
                              vector<int>{60, 204, 391, 626, 795, 798});
    });

    T.test("timing: k=2000, 100000 requests, unique busiest", [] {
        int k = 2000, n = 100000;
        vector<int> arrival(n), load(n);
        mt19937 rng(2);
        long long t = 0;
        for (int i = 0; i < n; i++) {
            t += 1 + rng() % 3;
            arrival[i] = (int)t;
            load[i] = 1 + (int)(rng() % 10000);
        }
        return expectAnyOrder(Solution().busiestServers(k, arrival, load), vector<int>{1268});
    });

    T.test("timing: k=500, 100000 heavy requests, two busiest", [] {
        int k = 500, n = 100000;
        vector<int> arrival(n), load(n);
        mt19937 rng(3);
        long long t = 0;
        for (int i = 0; i < n; i++) {
            t += 1 + rng() % 3;
            arrival[i] = (int)t;
            load[i] = 1 + (int)(rng() % 20000);
        }
        return expectAnyOrder(Solution().busiestServers(k, arrival, load), vector<int>{243, 255});
    });

    T.test("timing: k=100000 servers, 100000 requests, all tie", [] {
        int k = 100000, n = 100000;
        vector<int> arrival(n), load(n);
        mt19937 rng(4);
        long long t = 0;
        for (int i = 0; i < n; i++) {
            t += 1 + rng() % 3;
            arrival[i] = (int)t;
            load[i] = 1 + (int)(rng() % 1000000000);
        }
        auto r = Solution().busiestServers(k, arrival, load);
        return expectEq((int)r.size(), 100000);  // every server handles exactly one request
    });

    return T.summary();
}
