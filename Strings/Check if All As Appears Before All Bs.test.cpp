// Hidden judge for "Check if All As Appears Before All Bs.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Check if All As Appears Before All Bs.cpp"

int main() {
    TestRunner T;

    T.test("Example 1: grouped a's before b's", [] {
        string s = "aaabbb";
        return expectEq(Solution().checkString(s), true);
    });

    T.test("Example 2: alternating characters", [] {
        string s = "abab";
        return expectEq(Solution().checkString(s), false);
    });

    T.test("Example 3: only b's", [] {
        string s = "bbb";
        return expectEq(Solution().checkString(s), true);
    });

    T.test("single a", [] {
        string s = "a";
        return expectEq(Solution().checkString(s), true);
    });

    T.test("single b", [] {
        string s = "b";
        return expectEq(Solution().checkString(s), true);
    });

    T.test("only a's", [] {
        string s = "aaaaa";
        return expectEq(Solution().checkString(s), true);
    });

    T.test("smallest valid mixed string", [] {
        string s = "ab";
        return expectEq(Solution().checkString(s), true);
    });

    T.test("smallest invalid mixed string", [] {
        string s = "ba";
        return expectEq(Solution().checkString(s), false);
    });

    T.test("a's after an initial b", [] {
        string s = "bbaa";
        return expectEq(Solution().checkString(s), false);
    });

    T.test("one transition near the end", [] {
        string s = "aaaab";
        return expectEq(Solution().checkString(s), true);
    });

    T.test("one transition followed by invalid a", [] {
        string s = "aaabaa";
        return expectEq(Solution().checkString(s), false);
    });

    T.test("maximum length valid string", [] {
        string s(100, 'a');
        s.back() = 'b';
        return expectEq(Solution().checkString(s), true);
    });

    return T.summary();
}
