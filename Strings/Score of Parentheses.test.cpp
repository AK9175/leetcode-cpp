// Hidden judge for "Score of Parentheses.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Score of Parentheses.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "()";
        return expectEq(Solution().scoreOfParentheses(s), 1);
    });

    T.test("Example 2", [] {
        string s = "(())";
        return expectEq(Solution().scoreOfParentheses(s), 2);
    });

    T.test("Example 3", [] {
        string s = "()()";
        return expectEq(Solution().scoreOfParentheses(s), 2);
    });

    T.test("pair followed by nested pair", [] {
        string s = "()(())";
        return expectEq(Solution().scoreOfParentheses(s), 3);
    });

    T.test("two pairs wrapped once", [] {
        string s = "(()())";
        return expectEq(Solution().scoreOfParentheses(s), 4);
    });

    T.test("nested group inside with a sibling", [] {
        string s = "(()(()))";
        return expectEq(Solution().scoreOfParentheses(s), 6);
    });

    T.test("sibling after inner nested group", [] {
        string s = "((())())";
        return expectEq(Solution().scoreOfParentheses(s), 6);
    });

    T.test("several top-level groups of different depth", [] {
        string s = "(())()((()))()";
        return expectEq(Solution().scoreOfParentheses(s), 8);
    });

    T.test("deeply mixed", [] {
        string s = "((()()(()))(()))";
        return expectEq(Solution().scoreOfParentheses(s), 20);
    });

    T.test("max n, 25 pairs side by side", [] {
        string s;
        for (int i = 0; i < 25; i++) s += "()";
        return expectEq(Solution().scoreOfParentheses(s), 25);
    });

    T.test("max n, 25 levels deep", [] {
        string s = string(25, '(') + string(25, ')');
        return expectEq(Solution().scoreOfParentheses(s), 16777216);
    });

    T.test("max n, two pairs at the bottom of 23 levels", [] {
        string s = string(23, '(') + "()()" + string(23, ')');
        return expectEq(Solution().scoreOfParentheses(s), 16777216);
    });

    T.test("max n, two deep groups side by side", [] {
        string s = string(12, '(') + string(12, ')') + string(13, '(') + string(13, ')');
        return expectEq(Solution().scoreOfParentheses(s), 6144);
    });

    return T.summary();
}
