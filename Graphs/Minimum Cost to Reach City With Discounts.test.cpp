// Hidden judge for "Minimum Cost to Reach City With Discounts.cpp" (the site doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Cost to Reach City With Discounts.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        int n = 5;
        vector<vector<int>> highways = {{0, 1, 4}, {2, 1, 3}, {1, 4, 11}, {3, 2, 3}, {3, 4, 2}};
        int discounts = 1;
        return expectEq(Solution().minimumCost(n, highways, discounts), 9);
    });

    T.test("Example 2", [] {
        int n = 4;
        vector<vector<int>> highways = {{1, 3, 17}, {1, 2, 7}, {3, 2, 5}, {0, 1, 6}, {3, 0, 20}};
        int discounts = 20;
        return expectEq(Solution().minimumCost(n, highways, discounts), 8);
    });

    T.test("Example 3", [] {
        int n = 4;
        vector<vector<int>> highways = {{0, 1, 3}, {2, 3, 2}};
        int discounts = 0;
        return expectEq(Solution().minimumCost(n, highways, discounts), -1);
    });

    T.test("Example 1 graph with no discounts", [] {
        int n = 5;
        vector<vector<int>> highways = {{0, 1, 4}, {2, 1, 3}, {1, 4, 11}, {3, 2, 3}, {3, 4, 2}};
        int discounts = 0;
        return expectEq(Solution().minimumCost(n, highways, discounts), 12);
    });

    T.test("two cities, one highway, one discount", [] {
        int n = 2;
        vector<vector<int>> highways = {{0, 1, 7}};
        int discounts = 1;
        return expectEq(Solution().minimumCost(n, highways, discounts), 3);
    });

    T.test("two cities, one highway, no discount", [] {
        int n = 2;
        vector<vector<int>> highways = {{0, 1, 7}};
        int discounts = 0;
        return expectEq(Solution().minimumCost(n, highways, discounts), 7);
    });

    T.test("every toll is zero", [] {
        int n = 3;
        vector<vector<int>> highways = {{0, 1, 0}, {1, 2, 0}};
        int discounts = 0;
        return expectEq(Solution().minimumCost(n, highways, discounts), 0);
    });

    T.test("a toll of 1 halves down to 0", [] {
        int n = 2;
        vector<vector<int>> highways = {{0, 1, 1}};
        int discounts = 1;
        return expectEq(Solution().minimumCost(n, highways, discounts), 0);
    });

    T.test("destination in another component", [] {
        int n = 4;
        vector<vector<int>> highways = {{0, 1, 5}, {2, 3, 5}};
        int discounts = 3;
        return expectEq(Solution().minimumCost(n, highways, discounts), -1);
    });

    T.test("without a discount the long route wins", [] {
        int n = 4;
        vector<vector<int>> highways = {{0, 3, 100}, {0, 1, 30}, {1, 2, 30}, {2, 3, 30}};
        int discounts = 0;
        return expectEq(Solution().minimumCost(n, highways, discounts), 90);
    });

    T.test("with a discount the short route wins", [] {
        int n = 4;
        vector<vector<int>> highways = {{0, 3, 100}, {0, 1, 30}, {1, 2, 30}, {2, 3, 30}};
        int discounts = 1;
        return expectEq(Solution().minimumCost(n, highways, discounts), 50);
    });

    T.test("fewer discounts than highways on the route", [] {
        int n = 5;
        vector<vector<int>> highways = {{0, 1, 10}, {1, 2, 10}, {2, 3, 10}, {3, 4, 10}};
        int discounts = 2;
        return expectEq(Solution().minimumCost(n, highways, discounts), 30);
    });

    T.test("far more discounts than highways on the route", [] {
        int n = 5;
        vector<vector<int>> highways = {{0, 1, 10}, {1, 2, 10}, {2, 3, 10}, {3, 4, 10}};
        int discounts = 500;
        return expectEq(Solution().minimumCost(n, highways, discounts), 20);
    });

    T.test("save the discount for the big toll ahead", [] {
        int n = 3;
        vector<vector<int>> highways = {{0, 1, 10}, {1, 2, 100}};
        int discounts = 1;
        return expectEq(Solution().minimumCost(n, highways, discounts), 60);
    });

    T.test("big toll at the far end of a chain", [] {
        int n = 5;
        vector<vector<int>> highways = {{0, 1, 10}, {1, 2, 10}, {2, 3, 10}, {3, 4, 100}};
        int discounts = 1;
        return expectEq(Solution().minimumCost(n, highways, discounts), 80);
    });

    T.test("two discounts, both needed later", [] {
        int n = 4;
        vector<vector<int>> highways = {{0, 1, 10}, {1, 2, 100}, {2, 3, 100}};
        int discounts = 2;
        return expectEq(Solution().minimumCost(n, highways, discounts), 110);
    });

    T.test("two discounts on a chain with a big tail", [] {
        int n = 5;
        vector<vector<int>> highways = {{0, 1, 10}, {1, 2, 10}, {2, 3, 10}, {3, 4, 100}};
        int discounts = 2;
        return expectEq(Solution().minimumCost(n, highways, discounts), 75);
    });

    T.test("cheapest arrival at the hub already spent the discount", [] {
        int n = 4;
        vector<vector<int>> highways = {{0, 2, 100}, {0, 1, 30}, {1, 2, 30}, {2, 3, 1000}};
        int discounts = 1;
        return expectEq(Solution().minimumCost(n, highways, discounts), 560);
    });

    T.test("three incomparable arrivals at one city", [] {
        int n = 6;
        vector<vector<int>> highways = {{0, 3, 100}, {0, 1, 30}, {1, 3, 30},
                                        {0, 2, 45},  {2, 3, 20}, {3, 4, 1000}, {4, 5, 1000}};
        int discounts = 2;
        return expectEq(Solution().minimumCost(n, highways, discounts), 1060);
    });

    T.test("two discounts spread over three equal tolls", [] {
        int n = 4;
        vector<vector<int>> highways = {{0, 1, 100}, {1, 2, 100}, {2, 3, 100}};
        int discounts = 2;
        return expectEq(Solution().minimumCost(n, highways, discounts), 200);
    });

    T.test("a discount spent on a zero toll is wasted", [] {
        int n = 3;
        vector<vector<int>> highways = {{0, 1, 0}, {1, 2, 9}};
        int discounts = 1;
        return expectEq(Solution().minimumCost(n, highways, discounts), 4);
    });

    T.test("cheapest arrival at the hub is the worst finisher", [] {
        int n = 6;
        vector<vector<int>> highways = {{0, 1, 2}, {0, 4, 13},  {1, 2, 3},
                                        {2, 3, 4}, {3, 4, 5}, {4, 5, 200}};
        int discounts = 1;
        return expectEq(Solution().minimumCost(n, highways, discounts), 113);
    });

    T.test("timing: 1000-city chain, max tolls, 500 discounts", [] {
        int n = 1000;
        vector<vector<int>> highways;
        for (int i = 1; i < n; i++) highways.push_back({i - 1, i, 100000});
        int discounts = 500;
        // 999 highways on the only route: 499 at full price, 500 halved.
        return expectEq(Solution().minimumCost(n, highways, discounts), 74900000);
    });

    T.test("timing: random 1000-city graph, 500 discounts", [] {
        int n = 1000;
        set<pair<int, int>> seen;
        vector<vector<int>> highways;
        mt19937 rng(5);
        while ((int)highways.size() < 1000) {
            int a = rng() % n, b = rng() % n;
            if (a == b) continue;
            if (!seen.insert({min(a, b), max(a, b)}).second) continue;
            highways.push_back({a, b, (int)(rng() % 100001)});
        }
        int discounts = 500;
        return expectEq(Solution().minimumCost(n, highways, discounts), 242800);
    });

    T.test("timing: 1000 cities, destination unreachable", [] {
        int n = 1000;
        set<pair<int, int>> seen;
        vector<vector<int>> highways;
        mt19937 rng(6);
        while ((int)highways.size() < 1000) {
            int a = rng() % (n / 2), b = rng() % (n / 2);
            if (a == b) continue;
            if (!seen.insert({min(a, b), max(a, b)}).second) continue;
            highways.push_back({a, b, (int)(rng() % 100001)});
        }
        int discounts = 500;
        return expectEq(Solution().minimumCost(n, highways, discounts), -1);
    });

    return T.summary();
}
