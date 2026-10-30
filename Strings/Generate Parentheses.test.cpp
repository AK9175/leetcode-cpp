// Hidden judge for "Generate Parentheses.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Generate Parentheses.cpp"

// For the small n the expected lists are spelled out in full. For larger n they would be
// unreadable, so those tests check the defining properties instead: the right number of
// strings, each of length 2n, each well-formed, and no string repeated. Since there is only
// one set of well-formed strings of a given length, those four properties pin the answer
// down exactly. `expectedCount` is passed in per test rather than computed here.
bool isWellFormedSet(const vector<string>& got, int n, int expectedCount) {
    if ((int)got.size() != expectedCount) return false;
    set<string> seen;
    for (const string& s : got) {
        if ((int)s.size() != 2 * n) return false;
        int bal = 0;
        for (char c : s) {
            if (c != '(' && c != ')') return false;
            bal += (c == '(') ? 1 : -1;
            if (bal < 0) return false;
        }
        if (bal != 0) return false;
        if (!seen.insert(s).second) return false;
    }
    return true;
}

bool contains(const vector<string>& got, const string& s) {
    return find(got.begin(), got.end(), s) != got.end();
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        int n = 3;
        return expectAnyOrder(Solution().generateParenthesis(n),
                             vector<string>{"((()))","(()())","(())()","()(())","()()()"});
    });

    T.test("Example 2", [] {
        int n = 1;
        return expectAnyOrder(Solution().generateParenthesis(n), vector<string>{"()"});
    });

    T.test("two pairs", [] {
        int n = 2;
        return expectAnyOrder(Solution().generateParenthesis(n), vector<string>{"(())","()()"});
    });

    T.test("four pairs, all fourteen combinations", [] {
        int n = 4;
        return expectAnyOrder(Solution().generateParenthesis(n),
                             vector<string>{"(((())))","((()()))","((())())","((()))()",
                                            "(()(()))","(()()())","(()())()","(())(())",
                                            "(())()()","()((()))","()(()())","()(())()",
                                            "()()(())","()()()()"});
    });

    T.test("five pairs", [] {
        int n = 5;
        vector<string> got = Solution().generateParenthesis(n);
        return expectValid(got.size(), isWellFormedSet(got, n, 42),
                           "42 distinct well-formed strings of length 10");
    });

    T.test("six pairs", [] {
        int n = 6;
        vector<string> got = Solution().generateParenthesis(n);
        return expectValid(got.size(), isWellFormedSet(got, n, 132),
                           "132 distinct well-formed strings of length 12");
    });

    T.test("seven pairs", [] {
        int n = 7;
        vector<string> got = Solution().generateParenthesis(n);
        return expectValid(got.size(), isWellFormedSet(got, n, 429),
                           "429 distinct well-formed strings of length 14");
    });

    T.test("max n, eight pairs (timing)", [] {
        int n = 8;
        vector<string> got = Solution().generateParenthesis(n);
        return expectValid(got.size(), isWellFormedSet(got, n, 1430),
                           "1430 distinct well-formed strings of length 16");
    });

    T.test("max n includes the fully nested and fully flat strings", [] {
        int n = 8;
        vector<string> got = Solution().generateParenthesis(n);
        bool ok = contains(got, "(((((((())))))))") && contains(got, "()()()()()()()()");
        return expectValid(got.size(), ok, "contains both extremes of the set");
    });

    // Deliberately reuses one Solution object, unlike the other tests: a generator that
    // accumulates into a member or a static would return a longer list the second time.
    T.test("calling twice on one object gives the same list", [] {
        int n = 3;
        Solution sol;
        vector<string> first = sol.generateParenthesis(n);
        vector<string> second = sol.generateParenthesis(n);
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        return expectEq(second, first);
    });

    return T.summary();
}
