// Hidden judge for "Queries on Number of Points Inside a Circle.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Queries on Number of Points Inside a Circle.cpp"

// The perf outputs are 500 long; compare a {size, sum, first, last} digest.
static vector<long long> digest(const vector<int>& v) {
    long long sum = 0;
    for (int x : v) sum += x;
    return {(long long)v.size(), sum, v.empty() ? 0 : (long long)v.front(),
            v.empty() ? 0 : (long long)v.back()};
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<vector<int>> points = {{1, 3}, {3, 3}, {5, 3}, {2, 2}};
        vector<vector<int>> queries = {{2, 3, 1}, {4, 3, 1}, {1, 1, 2}};
        return expectEq(Solution().countPoints(points, queries), vector<int>{3, 2, 2});
    });

    T.test("Example 2", [] {
        vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
        vector<vector<int>> queries = {{1, 2, 2}, {2, 2, 2}, {4, 3, 2}, {4, 3, 3}};
        return expectEq(Solution().countPoints(points, queries), vector<int>{2, 3, 2, 4});
    });

    T.test("single point inside a single circle", [] {
        vector<vector<int>> points = {{3, 3}};
        vector<vector<int>> queries = {{3, 3, 1}};
        return expectEq(Solution().countPoints(points, queries), vector<int>{1});
    });

    T.test("point exactly on the border counts as inside", [] {
        vector<vector<int>> points = {{0, 2}};
        vector<vector<int>> queries = {{0, 0, 2}};  // distance 2 == radius 2
        return expectEq(Solution().countPoints(points, queries), vector<int>{1});
    });

    T.test("point just outside is excluded (3-4-5 with r=4)", [] {
        vector<vector<int>> points = {{3, 4}};
        vector<vector<int>> queries = {{0, 0, 4}};  // distance 5 > radius 4
        return expectEq(Solution().countPoints(points, queries), vector<int>{0});
    });

    T.test("point exactly on a 3-4-5 border with r=5", [] {
        vector<vector<int>> points = {{3, 4}};
        vector<vector<int>> queries = {{0, 0, 5}};  // distance 5 == radius 5
        return expectEq(Solution().countPoints(points, queries), vector<int>{1});
    });

    T.test("duplicate points are each counted", [] {
        vector<vector<int>> points = {{2, 2}, {2, 2}, {2, 2}};
        vector<vector<int>> queries = {{2, 2, 1}};
        return expectEq(Solution().countPoints(points, queries), vector<int>{3});
    });

    T.test("no point lies inside the circle", [] {
        vector<vector<int>> points = {{10, 10}};
        vector<vector<int>> queries = {{0, 0, 1}};
        return expectEq(Solution().countPoints(points, queries), vector<int>{0});
    });

    T.test("unit circle keeps axis points, drops the diagonal", [] {
        vector<vector<int>> points = {{0, 1}, {1, 0}, {1, 1}, {2, 0}};
        vector<vector<int>> queries = {{0, 0, 1}};  // (1,1) is sqrt(2) away, excluded
        return expectEq(Solution().countPoints(points, queries), vector<int>{2});
    });

    T.test("two border lattice points at different radii", [] {
        vector<vector<int>> points = {{3, 4}, {5, 12}};  // distances 5 and 13 from origin
        vector<vector<int>> queries = {{0, 0, 5}, {0, 0, 13}};
        return expectEq(Solution().countPoints(points, queries), vector<int>{1, 2});
    });

    T.test("far corner points, only the center one is reached", [] {
        vector<vector<int>> points = {{0, 0}, {500, 500}};  // distance 707 > 500
        vector<vector<int>> queries = {{0, 0, 500}};
        return expectEq(Solution().countPoints(points, queries), vector<int>{1});
    });

    T.test("timing: 500 points, 500 queries, random", [] {
        mt19937 rng(1);
        vector<vector<int>> points, queries;
        for (int i = 0; i < 500; i++) points.push_back({(int)(rng() % 501), (int)(rng() % 501)});
        for (int i = 0; i < 500; i++)
            queries.push_back({(int)(rng() % 501), (int)(rng() % 501), 1 + (int)(rng() % 500)});
        return expectEq(digest(Solution().countPoints(points, queries)),
                        vector<long long>{500, 116486, 380, 400});
    });

    T.test("timing: 500 identical points at the center", [] {
        vector<vector<int>> points(500, {250, 250});
        mt19937 rng(3);
        vector<vector<int>> queries;
        for (int i = 0; i < 500; i++)
            queries.push_back({(int)(rng() % 501), (int)(rng() % 501), 1 + (int)(rng() % 500)});
        return expectEq(digest(Solution().countPoints(points, queries)),
                        vector<long long>{500, 149500, 500, 500});
    });

    T.test("timing: 500 max-radius queries cover every point", [] {
        mt19937 rng(4);
        vector<vector<int>> points;
        for (int i = 0; i < 500; i++) points.push_back({(int)(rng() % 501), (int)(rng() % 501)});
        vector<vector<int>> queries(500, {250, 250, 500});
        return expectEq(digest(Solution().countPoints(points, queries)),
                        vector<long long>{500, 250000, 500, 500});
    });

    return T.summary();
}
