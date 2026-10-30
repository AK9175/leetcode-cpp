// Hidden judge for "Brace Expansion II.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Brace Expansion II.cpp"

// Every word of the cartesian product of `groups`, sorted. Used only to spell out the
// expected answer of the two hardcoded performance inputs below.
vector<string> crossProduct(const vector<vector<string>>& groups) {
    vector<string> res{""};
    for (const auto& g : groups) {
        vector<string> nxt;
        for (const auto& a : res)
            for (const auto& b : g) nxt.push_back(a + b);
        res = std::move(nxt);
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string expression = "{a,b}{c,{d,e}}";
        return expectEq(Solution().braceExpansionII(expression),
                        vector<string>{"ac","ad","ae","bc","bd","be"});
    });

    T.test("Example 2", [] {
        string expression = "{{a,z},a{b,c},{ab,z}}";
        return expectEq(Solution().braceExpansionII(expression),
                        vector<string>{"a","ab","ac","z"});
    });

    T.test("single letter", [] {
        string expression = "a";
        return expectEq(Solution().braceExpansionII(expression), vector<string>{"a"});
    });

    T.test("plain word, no braces", [] {
        string expression = "abcd";
        return expectEq(Solution().braceExpansionII(expression), vector<string>{"abcd"});
    });

    T.test("all alternatives identical", [] {
        string expression = "{a,a,a}";
        return expectEq(Solution().braceExpansionII(expression), vector<string>{"a"});
    });

    T.test("lexicographic order, not by length", [] {
        string expression = "{z,az}{a,b}";
        return expectEq(Solution().braceExpansionII(expression),
                        vector<string>{"aza","azb","za","zb"});
    });

    T.test("deeply nested unions", [] {
        string expression = "{a,{b,{c,d}}}";
        return expectEq(Solution().braceExpansionII(expression),
                        vector<string>{"a","b","c","d"});
    });

    T.test("letters before, between and after braces", [] {
        string expression = "x{a,b}y{c,d}z";
        return expectEq(Solution().braceExpansionII(expression),
                        vector<string>{"xaycz","xaydz","xbycz","xbydz"});
    });

    T.test("duplicate word from two different branches", [] {
        string expression = "{ab,a{b,c}}";
        return expectEq(Solution().braceExpansionII(expression), vector<string>{"ab","ac"});
    });

    T.test("same set concatenated with itself", [] {
        string expression = "{a,b}{a,b}";
        return expectEq(Solution().braceExpansionII(expression),
                        vector<string>{"aa","ab","ba","bb"});
    });

    T.test("union of two concatenations", [] {
        string expression = "{{a,b}c,{d,e}f}";
        return expectEq(Solution().braceExpansionII(expression),
                        vector<string>{"ac","bc","df","ef"});
    });

    T.test("whole alphabet in one union", [] {
        string expression = "{a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}";
        vector<string> expected;
        for (char c = 'a'; c <= 'z'; ++c) expected.push_back(string(1, c));
        return expectEq(Solution().braceExpansionII(expression), expected);
    });

    // Redundant single-expression braces: the grammar says a union has k >= 2 members, so
    // the judge may never show these, but they must not confuse the parser.
    T.test("redundant single-expression braces", [] {
        string expression = "{{a,z},a{{f{{b,c},s{t}}}}}";
        return expectEq(Solution().braceExpansionII(expression),
                        vector<string>{"a","afb","afc","afst","z"});
    });

    T.test("max length, 12 pairs, 4096 words (timing check)", [] {
        string expression;
        vector<vector<string>> groups;
        for (int i = 0; i < 12; ++i) {
            char lo = char('a' + 2 * i), hi = char('a' + 2 * i + 1);
            expression += '{';
            expression += lo;
            expression += ',';
            expression += hi;
            expression += '}';
            groups.push_back({string(1, lo), string(1, hi)});
        }
        return expectEq(Solution().braceExpansionII(expression), crossProduct(groups));
    });

    T.test("max length, 14 levels of nesting (timing check)", [] {
        const int levels = 14;
        string expression;
        vector<string> expected;
        for (int i = 0; i < levels; ++i) {
            expression += '{';
            expression += char('a' + i);
            expression += ',';
            expected.push_back(string(1, char('a' + i)));
        }
        expression += char('a' + levels);
        expression += string(levels, '}');
        expected.push_back(string(1, char('a' + levels)));
        return expectEq(Solution().braceExpansionII(expression), expected);
    });

    return T.summary();
}
