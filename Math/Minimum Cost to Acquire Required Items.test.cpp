// Hidden judge for "Minimum Cost to Acquire Required Items.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Cost to Acquire Required Items.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        int cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2), 3LL);
    });

    T.test("Example 2", [] {
        int cost1 = 5, cost2 = 4, costBoth = 15, need1 = 2, need2 = 3;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2), 22LL);
    });

    T.test("Example 3", [] {
        int cost1 = 5, cost2 = 4, costBoth = 15, need1 = 0, need2 = 0;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2), 0LL);
    });

    T.test("only type 1 is needed", [] {
        int cost1 = 3, cost2 = 7, costBoth = 100, need1 = 5, need2 = 0;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2), 15LL);
    });

    T.test("only type 2 is needed", [] {
        int cost1 = 7, cost2 = 3, costBoth = 100, need1 = 0, need2 = 5;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2), 15LL);
    });

    T.test("both item beats buying the two singles", [] {
        int cost1 = 10, cost2 = 10, costBoth = 5, need1 = 4, need2 = 4;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2), 20LL);
    });

    T.test("both item too pricey, buy singles", [] {
        int cost1 = 2, cost2 = 3, costBoth = 100, need1 = 4, need2 = 4;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2), 20LL);
    });

    T.test("both item used only for the overlap", [] {
        int cost1 = 5, cost2 = 6, costBoth = 7, need1 = 10, need2 = 4;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2), 58LL);
    });

    T.test("both item cheaper than type 1 alone, used past the overlap", [] {
        int cost1 = 10, cost2 = 5, costBoth = 3, need1 = 7, need2 = 2;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2), 21LL);
    });

    T.test("very lopsided needs", [] {
        int cost1 = 4, cost2 = 5, costBoth = 6, need1 = 1000, need2 = 3;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2), 4006LL);
    });

    T.test("max needs and max costs, singles win (overflows int)", [] {
        int cost1 = 1000000, cost2 = 1000000, costBoth = 2000000;
        int need1 = 1000000000, need2 = 1000000000;
        // 2e9 units at 1e6 each = 2e15, far beyond a 32-bit int.
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2),
                        2000000000000000LL);
    });

    T.test("max needs, both item is cheapest", [] {
        int cost1 = 1000000, cost2 = 1000000, costBoth = 1;
        int need1 = 1000000000, need2 = 1000000000;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2),
                        1000000000LL);
    });

    T.test("max need on one type only", [] {
        int cost1 = 1000000, cost2 = 1, costBoth = 1000000;
        int need1 = 1000000000, need2 = 0;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2),
                        1000000000000000LL);
    });

    T.test("max needs, both item for all overlap plus leftover", [] {
        int cost1 = 1000000, cost2 = 1000000, costBoth = 1;
        int need1 = 1000000000, need2 = 999999999;
        return expectEq(Solution().minimumCost(cost1, cost2, costBoth, need1, need2),
                        1000000000LL);
    });

    return T.summary();
}
