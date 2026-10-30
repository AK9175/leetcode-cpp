// Hidden judge for "Reverse Words in a String.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Reverse Words in a String.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "the sky is blue";
        return expectEq(Solution().reverseWords(s), string("blue is sky the"));
    });

    T.test("Example 2", [] {
        string s = "  hello world  ";
        return expectEq(Solution().reverseWords(s), string("world hello"));
    });

    T.test("Example 3", [] {
        string s = "a good   example";
        return expectEq(Solution().reverseWords(s), string("example good a"));
    });

    T.test("single character", [] {
        string s = "a";
        return expectEq(Solution().reverseWords(s), string("a"));
    });

    T.test("one word padded with spaces", [] {
        string s = "   hello   ";
        return expectEq(Solution().reverseWords(s), string("hello"));
    });

    T.test("letters inside a word keep their order", [] {
        string s = "abc def";
        return expectEq(Solution().reverseWords(s), string("def abc"));
    });

    T.test("case and digits preserved", [] {
        string s = "Alice123 bob 42";
        return expectEq(Solution().reverseWords(s), string("42 bob Alice123"));
    });

    T.test("all one-letter words", [] {
        string s = "a b c d e";
        return expectEq(Solution().reverseWords(s), string("e d c b a"));
    });

    T.test("irregular spacing everywhere", [] {
        string s = "  x    y   z ";
        return expectEq(Solution().reverseWords(s), string("z y x"));
    });

    T.test("leading spaces only", [] {
        string s = "    end";
        return expectEq(Solution().reverseWords(s), string("end"));
    });

    T.test("trailing space only", [] {
        string s = "start ";
        return expectEq(Solution().reverseWords(s), string("start"));
    });

    T.test("max length, one long word", [] {
        string s(10000, 'a');
        return expectEq(Solution().reverseWords(s), string(10000, 'a'));
    });

    T.test("max length, one letter buried in spaces", [] {
        string s = string(4999, ' ') + "x" + string(5000, ' ');
        return expectEq(Solution().reverseWords(s), string("x"));
    });

    T.test("near max length, 2221 numbered words", [] {
        string s, expected;
        for (int i = 1; i <= 2221; ++i) s += (i > 1 ? " " : "") + to_string(i);
        for (int i = 2221; i >= 1; --i) expected += to_string(i) + (i > 1 ? " " : "");
        return expectEq(Solution().reverseWords(s), expected);
    });

    return T.summary();
}
