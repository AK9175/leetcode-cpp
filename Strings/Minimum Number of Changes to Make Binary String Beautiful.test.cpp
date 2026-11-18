// Hidden judge for "Minimum Number of Changes to Make Binary String Beautiful.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Number of Changes to Make Binary String Beautiful.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "1001";
        return expectEq(Solution().minChanges(s), 2);
    });

    T.test("Example 2", [] {
        string s = "10";
        return expectEq(Solution().minChanges(s), 1);
    });

    T.test("Example 3", [] {
        string s = "0000";
        return expectEq(Solution().minChanges(s), 0);
    });

    T.test("shortest beautiful string", [] {
        string s = "11";
        return expectEq(Solution().minChanges(s), 0);
    });

    T.test("shortest string needing a change", [] {
        string s = "01";
        return expectEq(Solution().minChanges(s), 1);
    });

    T.test("already beautiful, mixed blocks", [] {
        string s = "1100";
        return expectEq(Solution().minChanges(s), 0);
    });

    T.test("fully alternating, every pair differs", [] {
        string s = "101010";
        return expectEq(Solution().minChanges(s), 3);
    });

    T.test("mixed 22-length string", [] {
        string s = "0110101000011101010101";
        return expectEq(Solution().minChanges(s), 9);
    });

    T.test("timing: 100000 all zeros", [] {
        string s(100000, '0');
        return expectEq(Solution().minChanges(s), 0);
    });

    T.test("timing: 100000 alternating 0101...", [] {
        string s;
        for (int i = 0; i < 100000; i++) s += (i % 2) ? '1' : '0';
        return expectEq(Solution().minChanges(s), 50000);
    });

    T.test("timing: 100000 random bits", [] {
        string s(100000, '0');
        mt19937 rng(3);
        for (auto& c : s) c = (rng() & 1) ? '1' : '0';
        return expectEq(Solution().minChanges(s), 25028);
    });

    return T.summary();
}
