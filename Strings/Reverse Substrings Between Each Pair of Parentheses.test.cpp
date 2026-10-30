// Hidden judge for "Reverse Substrings Between Each Pair of Parentheses.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Reverse Substrings Between Each Pair of Parentheses.cpp"

// `times` copies of `unit`, concatenated. Only used to build the constraint-sized inputs
// below and to spell out their expected answers.
string repeated(const string& unit, int times) {
    string res;
    res.reserve(unit.size() * times);
    for (int i = 0; i < times; ++i) res += unit;
    return res;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "(abcd)";
        return expectEq(Solution().reverseParentheses(s), "dcba");
    });

    T.test("Example 2", [] {
        string s = "(u(love)i)";
        return expectEq(Solution().reverseParentheses(s), "iloveu");
    });

    T.test("Example 3", [] {
        string s = "(ed(et(oc))el)";
        return expectEq(Solution().reverseParentheses(s), "leetcode");
    });

    T.test("no parentheses at all", [] {
        string s = "abc";
        return expectEq(Solution().reverseParentheses(s), "abc");
    });

    T.test("single letter", [] {
        string s = "a";
        return expectEq(Solution().reverseParentheses(s), "a");
    });

    T.test("one empty pair, nothing else", [] {
        string s = "()";
        return expectEq(Solution().reverseParentheses(s), "");
    });

    T.test("empty pair inside an empty pair", [] {
        string s = "(())";
        return expectEq(Solution().reverseParentheses(s), "");
    });

    T.test("letters outside the brackets", [] {
        string s = "a(bcdefghijkl(mno)p)q";
        return expectEq(Solution().reverseParentheses(s), "apmnolkjihgfedcbq");
    });

    T.test("two sibling groups side by side", [] {
        string s = "(ab)(cd)";
        return expectEq(Solution().reverseParentheses(s), "badc");
    });

    T.test("redundant nesting around one letter", [] {
        string s = "((((a))))";
        return expectEq(Solution().reverseParentheses(s), "a");
    });

    T.test("empty pairs mixed with letters", [] {
        string s = "a()b(()c)";
        return expectEq(Solution().reverseParentheses(s), "abc");
    });

    T.test("groups separated by plain text", [] {
        string s = "ab(cd)ef(gh)ij";
        return expectEq(Solution().reverseParentheses(s), "abdcefhgij");
    });

    T.test("26 nesting levels, one distinct letter each", [] {
        string s;
        for (int i = 0; i < 26; ++i) s += string("(") + char('a' + i);
        s += string(26, ')');
        return expectEq(Solution().reverseParentheses(s), "bdfhjlnprtvxzywusqomkigeca");
    });

    T.test("max length, 1000 nested empty pairs (timing)", [] {
        string s = string(1000, '(') + string(1000, ')');
        return expectEq(Solution().reverseParentheses(s), "");
    });

    T.test("max length, 666 nesting levels of the same letter (timing)", [] {
        string s = repeated("(a", 666) + string(666, ')');
        return expectEq(Solution().reverseParentheses(s), string(666, 'a'));
    });

    T.test("max length, 500 flat groups (timing)", [] {
        string s = repeated("(ab)", 500);
        return expectEq(Solution().reverseParentheses(s), repeated("ba", 500));
    });

    T.test("max length, repeated mixed unit (timing)", [] {
        string s = repeated("a(bc(de)f)g", 181);
        return expectEq(Solution().reverseParentheses(s), repeated("afdecbg", 181));
    });

    return T.summary();
}
