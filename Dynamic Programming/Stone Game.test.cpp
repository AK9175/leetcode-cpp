// Hidden judge for "Stone Game.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Stone Game.cpp"

// NOTE: Under the official constraints (even pile count, odd total) Alice always wins,
// so every in-constraint input returns true. Tests #7-#13 below deliberately use
// OUT-OF-CONSTRAINT inputs (odd counts, even/tie totals) so a real minimax has
// something that returns false to verify against. A hardcoded `return true` passes
// the judge but will fail those.

int main() {
    TestRunner T;

    // ---- within the official constraints: all true ----

    T.test("Example 1", [] {
        vector<int> piles = {5, 3, 4, 5};
        return expectEq(Solution().stoneGame(piles), true);
    });

    T.test("Example 2", [] {
        vector<int> piles = {3, 7, 2, 3};
        return expectEq(Solution().stoneGame(piles), true);
    });

    T.test("smallest board, two piles", [] {
        vector<int> piles = {1, 2};
        return expectEq(Solution().stoneGame(piles), true);
    });

    T.test("two piles, bigger one last", [] {
        vector<int> piles = {3, 4};
        return expectEq(Solution().stoneGame(piles), true);
    });

    T.test("six piles, odd total", [] {
        vector<int> piles = {1, 2, 3, 4, 5, 6};
        return expectEq(Solution().stoneGame(piles), true);
    });

    T.test("timing: 500 piles within constraints", [] {
        int n = 500;
        vector<int> piles(n);
        mt19937 rng(42);
        long long sum = 0;
        for (int i = 0; i < n; i++) { piles[i] = 1 + (int)(rng() % 500); sum += piles[i]; }
        if (sum % 2 == 0) piles[0] = (piles[0] == 500 ? 499 : piles[0] + 1);
        return expectEq(Solution().stoneGame(piles), true);
    });

    // ---- out of constraints: exercise the general minimax (can be false) ----

    T.test("general: single pile, first player takes it", [] {
        vector<int> piles = {5};
        return expectEq(Solution().stoneGame(piles), true);
    });

    T.test("general: two equal piles end in a tie, not a win", [] {
        vector<int> piles = {4, 4};
        return expectEq(Solution().stoneGame(piles), false);
    });

    T.test("general: four equal piles tie", [] {
        vector<int> piles = {5, 5, 5, 5};
        return expectEq(Solution().stoneGame(piles), false);
    });

    T.test("general: odd count where the first player loses", [] {
        vector<int> piles = {1, 5, 2};
        return expectEq(Solution().stoneGame(piles), false);
    });

    T.test("general: big middle pile is unreachable first", [] {
        vector<int> piles = {1, 100, 1};
        return expectEq(Solution().stoneGame(piles), false);
    });

    T.test("general: odd count, all equal, first player wins", [] {
        vector<int> piles = {5, 5, 5};
        return expectEq(Solution().stoneGame(piles), true);
    });

    T.test("general: 500 equal piles tie", [] {
        vector<int> piles(500, 7);
        return expectEq(Solution().stoneGame(piles), false);
    });

    return T.summary();
}
