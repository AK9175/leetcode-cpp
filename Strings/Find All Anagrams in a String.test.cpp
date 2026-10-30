// Hidden judge for "Find All Anagrams in a String.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Find All Anagrams in a String.cpp"

// Expected answer for the big tests: every index from lo to hi inclusive.
static vector<int> range(int lo, int hi) {
    vector<int> out;
    for (int i = lo; i <= hi; ++i) out.push_back(i);
    return out;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "cbaebabacd";
        string p = "abc";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{0, 6});
    });

    T.test("Example 2", [] {
        string s = "abab";
        string p = "ab";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{0, 1, 2});
    });

    T.test("p longer than s", [] {
        string s = "ab";
        string p = "abc";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{});
    });

    T.test("equal lengths, anagram", [] {
        string s = "ba";
        string p = "ab";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{0});
    });

    T.test("equal lengths, not an anagram", [] {
        string s = "ab";
        string p = "aa";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{});
    });

    T.test("single character p with several hits", [] {
        string s = "aabaa";
        string p = "a";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{0, 1, 3, 4});
    });

    T.test("single character, no hit", [] {
        string s = "a";
        string p = "b";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{});
    });

    T.test("no matching window", [] {
        string s = "abcdef";
        string p = "xyz";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{});
    });

    T.test("p has repeated letters", [] {
        string s = "baaab";
        string p = "aab";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{0, 2});
    });

    T.test("every character the same", [] {
        string s = "aaaa";
        string p = "aa";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{0, 1, 2});
    });

    T.test("match only at the last window", [] {
        string s = "xxab";
        string p = "ba";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{2});
    });

    T.test("match only at the first window", [] {
        string s = "abxx";
        string p = "ba";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{0});
    });

    T.test("every window matches", [] {
        string s = "abcabc";
        string p = "abc";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{0, 1, 2, 3});
    });

    T.test("max n, s and p both full length and anagrams (timing check)", [] {
        string s = string(15000, 'a') + string(15000, 'b');
        string p = string(15000, 'b') + string(15000, 'a');
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{0});
    });

    T.test("max n, all one character and p half as long (timing check)", [] {
        string s(30000, 'a');
        string p(15000, 'a');
        return expectAnyOrder(Solution().findAnagrams(s, p), range(0, 15000));
    });

    T.test("max n, every window matches (timing check)", [] {
        string s;
        for (int i = 0; i < 10000; ++i) s += "aab";
        string p = "aba";
        return expectAnyOrder(Solution().findAnagrams(s, p), range(0, 29997));
    });

    T.test("max n, single match at the very end (timing check)", [] {
        string s = string(29999, 'a') + "b";
        string p = "ab";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{29998});
    });

    T.test("max n, p present but nothing matches (timing check)", [] {
        string s(30000, 'a');
        string p = string(14999, 'a') + "b";
        return expectAnyOrder(Solution().findAnagrams(s, p), vector<int>{});
    });

    return T.summary();
}
