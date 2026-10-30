// Hidden judge for "Evaluate the Bracket Pairs of a String.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Evaluate the Bracket Pairs of a String.cpp"

// `times` copies of `unit`, concatenated. Only used to spell out the expected answers of
// the constraint-sized inputs below.
string repeated(const string& unit, int times) {
    string res;
    res.reserve(unit.size() * times);
    for (int i = 0; i < times; ++i) res += unit;
    return res;
}

// The i-th of a family of distinct 4-letter lowercase keys (i < 26^4).
string nthKey(int i) {
    string k(4, 'a');
    for (int p = 3; p >= 0; --p, i /= 26) k[p] = char('a' + i % 26);
    return k;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "(name)is(age)yearsold";
        vector<vector<string>> knowledge = {{"name","bob"},{"age","two"}};
        return expectEq(Solution().evaluate(s, knowledge), "bobistwoyearsold");
    });

    T.test("Example 2", [] {
        string s = "hi(name)";
        vector<vector<string>> knowledge = {{"a","b"}};
        return expectEq(Solution().evaluate(s, knowledge), "hi?");
    });

    T.test("Example 3", [] {
        string s = "(a)(a)(a)aaa";
        vector<vector<string>> knowledge = {{"a","yes"}};
        return expectEq(Solution().evaluate(s, knowledge), "yesyesyesaaa");
    });

    T.test("no brackets at all", [] {
        string s = "abcdefg";
        vector<vector<string>> knowledge = {{"a","1"},{"abcdefg","x"}};
        return expectEq(Solution().evaluate(s, knowledge), "abcdefg");
    });

    T.test("whole string is one known pair", [] {
        string s = "(key)";
        vector<vector<string>> knowledge = {{"key","value"}};
        return expectEq(Solution().evaluate(s, knowledge), "value");
    });

    T.test("empty knowledge, every pair unknown", [] {
        string s = "x(a)y(bc)z";
        vector<vector<string>> knowledge = {};
        return expectEq(Solution().evaluate(s, knowledge), "x?y?z");
    });

    T.test("keys that are prefixes of each other", [] {
        string s = "(ab)(a)b(abc)";
        vector<vector<string>> knowledge = {{"a","x"},{"ab","y"},{"abc","z"}};
        return expectEq(Solution().evaluate(s, knowledge), "yxbz");
    });

    T.test("adjacent pairs, mixed known and unknown", [] {
        string s = "(p)(q)(p)(r)";
        vector<vector<string>> knowledge = {{"p","one"},{"r","three"}};
        return expectEq(Solution().evaluate(s, knowledge), "one?onethree");
    });

    T.test("value equals another key's text", [] {
        string s = "(a)(b)";
        vector<vector<string>> knowledge = {{"a","b"},{"b","a"}};
        return expectEq(Solution().evaluate(s, knowledge), "ba");
    });

    T.test("max-length key and value, unused entries", [] {
        string s = "pre(abcdefghij)post";
        vector<vector<string>> knowledge = {{"zzzzzzzzzz","qwertyuiop"},
                                           {"abcdefghij","jihgfedcba"},
                                           {"abcdefghi","nope"}};
        return expectEq(Solution().evaluate(s, knowledge), "prejihgfedcbapost");
    });

    T.test("key letters also appear as plain text around it", [] {
        string s = "name(name)name";
        vector<vector<string>> knowledge = {{"name","N"}};
        return expectEq(Solution().evaluate(s, knowledge), "nameNname");
    });

    T.test("many pairs sharing one key, one letter of plain text", [] {
        string s = repeated("(k)", 1000) + "k";
        vector<vector<string>> knowledge = {{"k","vv"}};
        return expectEq(Solution().evaluate(s, knowledge), repeated("vv", 1000) + "k");
    });

    T.test("max s, 25000 repeats of one known pair (timing)", [] {
        string s = repeated("(ab)", 25000);
        vector<vector<string>> knowledge = {{"ab","abcdefghij"}};
        return expectEq(Solution().evaluate(s, knowledge), repeated("abcdefghij", 25000));
    });

    T.test("max s, all pairs unknown, empty knowledge (timing)", [] {
        string s = repeated("(qqqq)", 16666);
        vector<vector<string>> knowledge = {};
        return expectEq(Solution().evaluate(s, knowledge), repeated("?", 16666));
    });

    T.test("max knowledge, s uses first and last key (timing)", [] {
        vector<vector<string>> knowledge;
        knowledge.reserve(100000);
        for (int i = 0; i < 100000; ++i) knowledge.push_back({nthKey(i), "z" + nthKey(i)});
        string s = "(" + nthKey(0) + ")mid(" + nthKey(99999) + ")";
        return expectEq(Solution().evaluate(s, knowledge),
                        "z" + nthKey(0) + "mid" + "z" + nthKey(99999));
    });

    return T.summary();
}
