// Hidden judge for "Minimum Stations to Reach Destination.cpp".
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Stations to Reach Destination.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        int n = 5;
        vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
        vector<int> stations = {2};
        int source = 0;
        int destination = 4;
        int p = 2;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{1, 4});
    });

    T.test("Example 2", [] {
        int n = 3;
        vector<vector<int>> roads = {{0, 1}, {1, 2}};
        vector<int> stations = {};
        int source = 0;
        int destination = 2;
        int p = 5;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{0, 2});
    });

    T.test("Example 3", [] {
        int n = 3;
        vector<vector<int>> roads = {{0, 1}, {1, 2}};
        vector<int> stations = {};
        int source = 0;
        int destination = 2;
        int p = 1;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{-1, -1});
    });

    T.test("1-indexed cities, city 0 unused, forced detour to city 5", [] {
        int n = 8;
        vector<vector<int>> roads = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {6, 7}};
        vector<int> stations = {5};
        int source = 1;
        int destination = 7;
        int p = 4;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{1, 7});
    });

    T.test("side trip to a station, one road driven twice", [] {
        int n = 6;
        vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {2, 5}};
        vector<int> stations = {5};
        int source = 0;
        int destination = 4;
        int p = 3;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{1, 6});
    });

    T.test("fewer stations wins over fewer roads", [] {
        int n = 7;
        vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {0, 4}, {4, 5}, {5, 6}, {6, 3}};
        vector<int> stations = {1, 2, 5};
        int source = 0;
        int destination = 3;
        int p = 2;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{1, 4});
    });

    T.test("source equals destination", [] {
        int n = 3;
        vector<vector<int>> roads = {{0, 1}, {1, 2}};
        vector<int> stations = {1};
        int source = 0;
        int destination = 0;
        int p = 4;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{0, 0});
    });

    T.test("no roads at all", [] {
        int n = 3;
        vector<vector<int>> roads = {};
        vector<int> stations = {1, 2};
        int source = 0;
        int destination = 2;
        int p = 5;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{-1, -1});
    });

    T.test("destination holds a station", [] {
        int n = 3;
        vector<vector<int>> roads = {{0, 1}, {1, 2}};
        vector<int> stations = {2};
        int source = 0;
        int destination = 2;
        int p = 5;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{1, 2});
    });

    T.test("refuel is mandatory even with a full tank", [] {
        int n = 4;
        vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}};
        vector<int> stations = {1};
        int source = 0;
        int destination = 3;
        int p = 10;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{1, 3});
    });

    T.test("only station is a dead end, still stranded", [] {
        int n = 5;
        vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {1, 4}};
        vector<int> stations = {4};
        int source = 0;
        int destination = 3;
        int p = 2;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{-1, -1});
    });

    T.test("destination in another component", [] {
        int n = 6;
        vector<vector<int>> roads = {{0, 1}, {1, 2}, {3, 4}, {4, 5}};
        vector<int> stations = {1, 4};
        int source = 0;
        int destination = 5;
        int p = 3;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{-1, -1});
    });

    T.test("two equal-length paths, one passes a station", [] {
        int n = 4;
        vector<vector<int>> roads = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
        vector<int> stations = {1};
        int source = 0;
        int destination = 3;
        int p = 2;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{0, 2});
    });

    T.test("timing: 1000-city chain, station every 5 cities, p = 5", [] {
        int n = 1000;
        vector<vector<int>> roads;
        for (int i = 0; i + 1 < n; i++) roads.push_back({i, i + 1});
        vector<int> stations;
        for (int i = 5; i <= 995; i += 5) stations.push_back(i);
        int source = 0;
        int destination = 999;
        int p = 5;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{199, 999});
    });

    T.test("timing: 1000-city chain, no stations, p = 1000", [] {
        int n = 1000;
        vector<vector<int>> roads;
        for (int i = 0; i + 1 < n; i++) roads.push_back({i, i + 1});
        vector<int> stations = {};
        int source = 0;
        int destination = 999;
        int p = 1000;
        return expectEq(Solution().minStationsAndRoads(n, roads, stations, source, destination, p),
                        vector<int>{0, 999});
    });

    return T.summary();
}
