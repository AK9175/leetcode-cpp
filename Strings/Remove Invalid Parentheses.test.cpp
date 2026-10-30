// Hidden judge for "Remove Invalid Parentheses.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Remove Invalid Parentheses.cpp"

// Shape check for the two big tests, whose answer sets are far too large to list.
// It does not work out the answer: `wantCount` and `wantLen` are given, and each
// returned string only has to be distinct, that long, a valid parenthesisation, and
// reachable from s by dropping parentheses alone (every letter of s still present).
static bool isAnswerSet(const string& s, const vector<string>& got,
                        size_t wantCount, size_t wantLen) {
    if (got.size() != wantCount) return false;
    set<string> seen;
    for (const string& t : got) {
        if (t.size() != wantLen) return false;
        if (!seen.insert(t).second) return false;   // the answer must be unique strings
        int bal = 0;
        for (char c : t) {
            if (c == '(') bal++;
            else if (c == ')' && --bal < 0) return false;
        }
        if (bal != 0) return false;
        size_t i = 0;
        for (char c : s) {
            if (i < t.size() && t[i] == c) i++;
            else if (c != '(' && c != ')') return false;   // a letter went missing
        }
        if (i != t.size()) return false;
    }
    return true;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "()())()";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{"(())()", "()()()"});
    });

    T.test("Example 2", [] {
        string s = "(a)())()";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{"(a())()", "(a)()()"});
    });

    T.test("Example 3", [] {
        string s = ")(";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{""});
    });

    T.test("single letter, nothing to remove", [] {
        string s = "a";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{"a"});
    });

    T.test("single open parenthesis", [] {
        string s = "(";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{""});
    });

    T.test("already valid, nothing to remove", [] {
        string s = "()";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{"()"});
    });

    T.test("letters only, no parentheses", [] {
        string s = "abc";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{"abc"});
    });

    T.test("one extra open parenthesis", [] {
        string s = "(()";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{"()"});
    });

    T.test("valid prefix then a reversed pair", [] {
        string s = "(()))(";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{"(())"});
    });

    T.test("unmatched close before an unmatched open", [] {
        string s = ")()(";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{"()"});
    });

    T.test("letters between nested parentheses", [] {
        string s = "(a(b(c)d)e)f)";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{"(a(b(c)d)e)f", "(a(b(c)d)ef)",
                                             "(a(b(c)de)f)", "(a(b(cd)e)f)"});
    });

    T.test("mostly closes, one answer survives", [] {
        string s = ")()))))()()(";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{"()()()"});
    });

    T.test("several ways to pair up", [] {
        string s = "(()(()(()(";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{"(()())", "(())()", "()(())", "()()()"});
    });

    T.test("all opens, max parentheses", [] {
        string s = "((((((((((((((((((((";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{""});
    });

    T.test("all closes then all opens", [] {
        string s = "))))))))))((((((((((";
        return expectAnyOrder(Solution().removeInvalidParentheses(s),
                              vector<string>{""});
    });

    T.test("max parentheses, 98 answers (timing check)", [] {
        string s = "((()(()()(()(()())()";
        vector<string> got = Solution().removeInvalidParentheses(s);
        return expectValid(got.size(), isAnswerSet(s, got, 98, 16),
                           "98 distinct valid strings of length 16");
    });

    T.test("max length and parentheses, 407 answers (timing check)", [] {
        string s = "(a(c(()(e)((de(()((()()()";
        vector<string> got = Solution().removeInvalidParentheses(s);
        return expectValid(got.size(), isAnswerSet(s, got, 407, 17),
                           "407 distinct valid strings of length 17");
    });

    return T.summary();
}
