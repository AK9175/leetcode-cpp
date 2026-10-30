// Hidden judge for "Valid Parenthesis String.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Valid Parenthesis String.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "()";
        return expectEq(Solution().checkValidString(s), true);
    });

    T.test("Example 2", [] {
        string s = "(*)";
        return expectEq(Solution().checkValidString(s), true);
    });

    T.test("Example 3", [] {
        string s = "(*))";
        return expectEq(Solution().checkValidString(s), true);
    });

    T.test("Example 4", [] {
        string s = "(";
        return expectEq(Solution().checkValidString(s), false);
    });

    T.test("single star", [] {
        string s = "*";
        return expectEq(Solution().checkValidString(s), true);
    });

    T.test("single close paren", [] {
        string s = ")";
        return expectEq(Solution().checkValidString(s), false);
    });

    T.test("star before close", [] {
        string s = "*)";
        return expectEq(Solution().checkValidString(s), true);
    });

    T.test("star after close can't help", [] {
        string s = ")*";
        return expectEq(Solution().checkValidString(s), false);
    });

    T.test("star before open can't help", [] {
        string s = "*(";
        return expectEq(Solution().checkValidString(s), false);
    });

    T.test("stars outnumber opens but come first", [] {
        string s = "**((";
        return expectEq(Solution().checkValidString(s), false);
    });

    T.test("trailing unmatched open after balanced part", [] {
        string s = "(*)(";
        return expectEq(Solution().checkValidString(s), false);
    });

    T.test("two stars can't cover three opens", [] {
        string s = "(((**";
        return expectEq(Solution().checkValidString(s), false);
    });

    T.test("several stars, some unneeded", [] {
        string s = "(*()*)*";
        return expectEq(Solution().checkValidString(s), true);
    });

    T.test("mixed, needs one star as open", [] {
        string s = "(()*))";
        return expectEq(Solution().checkValidString(s), true);
    });

    T.test("long tricky mixed string", [] {
        string s = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()";
        return expectEq(Solution().checkValidString(s), true);
    });

    T.test("long mixed string, many unclosed opens", [] {
        string s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
        return expectEq(Solution().checkValidString(s), false);
    });

    T.test("medium mixed string, few stars", [] {
        string s = "(())((())()()(*)(*()(())())())()()((()())((()))(*";
        return expectEq(Solution().checkValidString(s), false);
    });

    T.test("max n, 50 opens then 50 stars", [] {
        string s = string(50, '(') + string(50, '*');
        return expectEq(Solution().checkValidString(s), true);
    });

    T.test("max n, 50 stars then 50 opens", [] {
        string s = string(50, '*') + string(50, '(');
        return expectEq(Solution().checkValidString(s), false);
    });

    T.test("max n, all stars (timing check)", [] {
        string s = string(100, '*');
        return expectEq(Solution().checkValidString(s), true);
    });

    T.test("max n, random mix (timing check)", [] {
        mt19937 rng(678);
        string s;
        for (int i = 0; i < 100; i++) s += "()*"[rng() % 3];
        Solution().checkValidString(s);
        return noCheck();
    });

    return T.summary();
}
