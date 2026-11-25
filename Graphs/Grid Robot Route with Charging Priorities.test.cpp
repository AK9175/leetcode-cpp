// Hidden judge for "Grid Robot Route with Charging Priorities.cpp".
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Grid Robot Route with Charging Priorities.cpp"

int main() {
    TestRunner T;

    T.test("Example 1: detour avoids charger", [] {
        vector<string> grid = {"SCT", "..."};
        return expectEq(Solution().optimalChargingCost(grid), vector<int>{0, 4, 4});
    });

    T.test("Example 2: one charger with smaller capacity", [] {
        vector<string> grid = {"SC...", ".###.", ".###T", ".C..."};
        return expectEq(Solution().optimalChargingCost(grid), vector<int>{1, 4, 8});
    });

    T.test("direct route without charger", [] {
        vector<string> grid = {"S.T"};
        return expectEq(Solution().optimalChargingCost(grid), vector<int>{0, 2, 2});
    });

    T.test("only route passes through one charger", [] {
        vector<string> grid = {"SCT"};
        return expectEq(Solution().optimalChargingCost(grid), vector<int>{1, 1, 2});
    });

    T.test("only route passes through two chargers", [] {
        vector<string> grid = {"SCCT"};
        return expectEq(Solution().optimalChargingCost(grid), vector<int>{2, 1, 3});
    });

    T.test("unreachable target", [] {
        vector<string> grid = {"S#T"};
        return expectEq(Solution().optimalChargingCost(grid), vector<int>{-1, -1, -1});
    });

    T.test("blocked target with isolated charger", [] {
        vector<string> grid = {"S#C", "###", "..T"};
        return expectEq(Solution().optimalChargingCost(grid), vector<int>{-1, -1, -1});
    });

    T.test("zero-charge route has priority over shorter charged route", [] {
        vector<string> grid = {"S.C", "...", "..T"};
        return expectEq(Solution().optimalChargingCost(grid), vector<int>{0, 4, 4});
    });

    T.test("one-row route with repeated charger cells", [] {
        vector<string> grid = {"SCCCT"};
        return expectEq(Solution().optimalChargingCost(grid), vector<int>{3, 1, 4});
    });

    T.test("open maximum-size grid", [] {
        vector<string> grid(10, string(10, '.'));
        grid[0][0] = 'S';
        grid[9][9] = 'T';
        return expectEq(Solution().optimalChargingCost(grid), vector<int>{0, 18, 18});
    });

    T.test("small grid with charger detour", [] {
        vector<string> grid = {"S.C.", ".##.", "...T"};
        return expectEq(Solution().optimalChargingCost(grid), vector<int>{0, 5, 5});
    });

    return T.summary();
}
