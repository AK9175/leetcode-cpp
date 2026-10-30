// Hidden judge for "Longest Valid Parentheses.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Longest Valid Parentheses.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "(()";
        return expectEq(Solution().longestValidParentheses(s), 2);
    });

    T.test("Example 2", [] {
        string s = ")()())";
        return expectEq(Solution().longestValidParentheses(s), 4);
    });

    T.test("Example 3", [] {
        string s = "";
        return expectEq(Solution().longestValidParentheses(s), 0);
    });

    T.test("single open", [] {
        string s = "(";
        return expectEq(Solution().longestValidParentheses(s), 0);
    });

    T.test("single close", [] {
        string s = ")";
        return expectEq(Solution().longestValidParentheses(s), 0);
    });

    T.test("reversed pair", [] {
        string s = ")(";
        return expectEq(Solution().longestValidParentheses(s), 0);
    });

    T.test("unmatched open splits two runs", [] {
        string s = "()(()";
        return expectEq(Solution().longestValidParentheses(s), 2);
    });

    T.test("adjacent pair then nested group join", [] {
        string s = "()(())";
        return expectEq(Solution().longestValidParentheses(s), 6);
    });

    T.test("extra opens on the left", [] {
        string s = "((())";
        return expectEq(Solution().longestValidParentheses(s), 4);
    });

    T.test("extra close in the middle", [] {
        string s = "()(()))())(";
        return expectEq(Solution().longestValidParentheses(s), 6);
    });

    T.test("nested inside concatenation", [] {
        string s = "(()())";
        return expectEq(Solution().longestValidParentheses(s), 6);
    });

    T.test("longest run at the end", [] {
        string s = "))((()())()";
        return expectEq(Solution().longestValidParentheses(s), 8);
    });

    T.test("max n, all opens", [] {
        string s(30000, '(');
        return expectEq(Solution().longestValidParentheses(s), 0);
    });

    T.test("max n, deeply nested", [] {
        string s = string(15000, '(') + string(15000, ')');
        return expectEq(Solution().longestValidParentheses(s), 30000);
    });

    T.test("max n, pairs broken by one close in the middle", [] {
        string s;
        for (int i = 0; i < 7500; i++) s += "()";
        s += ")";
        for (int i = 0; i < 7499; i++) s += "()";
        s += "(";
        return expectEq(Solution().longestValidParentheses(s), 15000);
    });

    return T.summary();
}
