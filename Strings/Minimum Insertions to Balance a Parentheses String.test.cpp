// Hidden judge for "Minimum Insertions to Balance a Parentheses String.cpp"
// (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Insertions to Balance a Parentheses String.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "(()))";
        return expectEq(Solution().minInsertions(s), 1);
    });

    T.test("Example 2", [] {
        string s = "())";
        return expectEq(Solution().minInsertions(s), 0);
    });

    T.test("Example 3", [] {
        string s = "))())(";
        return expectEq(Solution().minInsertions(s), 3);
    });

    T.test("single open parenthesis", [] {
        string s = "(";
        return expectEq(Solution().minInsertions(s), 2);
    });

    T.test("single close parenthesis", [] {
        string s = ")";
        return expectEq(Solution().minInsertions(s), 2);
    });

    T.test("one close short", [] {
        string s = "()";
        return expectEq(Solution().minInsertions(s), 1);
    });

    T.test("close pair with no open", [] {
        string s = "))";
        return expectEq(Solution().minInsertions(s), 1);
    });

    T.test("odd run of closes", [] {
        string s = ")))";
        return expectEq(Solution().minInsertions(s), 3);
    });

    T.test("close pair arrives before its open", [] {
        string s = ")()";
        return expectEq(Solution().minInsertions(s), 3);
    });

    T.test("open then an odd tail of closes", [] {
        string s = "()))";
        return expectEq(Solution().minInsertions(s), 2);
    });

    T.test("two opens, nothing closed", [] {
        string s = "((";
        return expectEq(Solution().minInsertions(s), 4);
    });

    T.test("already balanced, sequential and nested", [] {
        string s = "())(())))";
        return expectEq(Solution().minInsertions(s), 0);
    });

    T.test("already balanced, nesting inside", [] {
        string s = "(())())))";
        return expectEq(Solution().minInsertions(s), 0);
    });

    T.test("every open one close short", [] {
        string s = "()()()";
        return expectEq(Solution().minInsertions(s), 3);
    });

    T.test("mixed run, closes leading", [] {
        string s = "))())())()())()))()))";
        return expectEq(Solution().minInsertions(s), 6);
    });

    T.test("long mixed run of both", [] {
        string s = "))())())()())()))()))))(()))())))))(()()())()())((()())))()";
        return expectEq(Solution().minInsertions(s), 19);
    });

    T.test("max n, all opens, largest possible answer (timing check)", [] {
        string s(100000, '(');
        return expectEq(Solution().minInsertions(s), 200000);   // two ')' per '('
    });

    T.test("max n, all closes (timing check)", [] {
        string s(100000, ')');
        return expectEq(Solution().minInsertions(s), 50000);    // one '(' per '))'
    });

    T.test("max n, already balanced (timing check)", [] {
        string s;
        s.reserve(99999);
        for (int i = 0; i < 33333; i++) s += "())";
        return expectEq(Solution().minInsertions(s), 0);
    });

    return T.summary();
}
