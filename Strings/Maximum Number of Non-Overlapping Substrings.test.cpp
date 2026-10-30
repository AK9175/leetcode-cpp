// Hidden judge for "Maximum Number of Non-Overlapping Substrings.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Maximum Number of Non-Overlapping Substrings.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "adefaddaccc";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"e","f","ccc"});
    });

    T.test("Example 2", [] {
        string s = "abbaccd";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"d","bb","cc"});
    });

    T.test("single character", [] {
        string s = "a";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"a"});
    });

    T.test("all same character", [] {
        string s = "aaaa";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"aaaa"});
    });

    T.test("all distinct characters", [] {
        string s = "abcde";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"a","b","c","d","e"});
    });

    T.test("two interleaved letters, only whole string works", [] {
        string s = "abab";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"abab"});
    });

    T.test("odd palindrome, innermost letter alone", [] {
        string s = "abcba";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"c"});
    });

    T.test("even palindrome, innermost pair", [] {
        string s = "abccba";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"cc"});
    });

    T.test("inner letter pulls in a letter that starts further left", [] {
        string s = "abacdcb";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"d"});
    });

    T.test("everything entangled into one piece", [] {
        string s = "cabcccbaa";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"cabcccbaa"});
    });

    T.test("letters surrounded by a repeated separator", [] {
        string s = "zazbzcz";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"a","b","c"});
    });

    T.test("outer range skipped, inner and trailing kept", [] {
        string s = "baabbc";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"aa","c"});
    });

    T.test("interleaved prefix, then two blocks", [] {
        string s = "ababccdd";
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{"abab","cc","dd"});
    });

    T.test("max n, one repeated letter", [] {
        string s(100000, 'z');
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{string(100000, 'z')});
    });

    T.test("max n, 26 consecutive blocks", [] {
        string s;
        vector<string> expected;
        for (int c = 0; c < 26; c++) {
            int len = 100000 / 26 + (c < 100000 % 26 ? 1 : 0);
            s += string(len, 'a' + c);
            expected.push_back(string(len, 'a' + c));
        }
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), expected);
    });

    T.test("max n, alphabet repeated (whole string only)", [] {
        string s;
        for (int i = 0; i < 100000; i++) s += 'a' + i % 26;
        string whole = s;
        return expectAnyOrder(Solution().maxNumOfSubstrings(s), vector<string>{whole});
    });

    return T.summary();
}
