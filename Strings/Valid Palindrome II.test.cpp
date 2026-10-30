// Hidden judge for "Valid Palindrome II.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Valid Palindrome II.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "aba";
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("Example 2", [] {
        string s = "abca";
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("Example 3", [] {
        string s = "abc";
        return expectEq(Solution().validPalindrome(s), false);
    });

    T.test("single character", [] {
        string s = "a";
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("two different characters", [] {
        string s = "ab";
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("already a palindrome, even length", [] {
        string s = "abba";
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("already a palindrome, odd length", [] {
        string s = "racecar";
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("extra character at the end", [] {
        string s = "racecarx";
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("extra character at the front", [] {
        string s = "xracecar";
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("both ends wrong, two deletions needed", [] {
        string s = "xabccbay";
        return expectEq(Solution().validPalindrome(s), false);
    });

    T.test("both skips look possible but only one works", [] {
        string s = "baaba";
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("101 characters, one stray 'u' deep inside", [] {
        string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("mismatch buried in the middle of a long string", [] {
        string filler;
        mt19937 rng(2026);
        for (int k = 0; k < 49997; k++) filler += char('a' + rng() % 26);
        string s = filler + "eeeed" + string(filler.rbegin(), filler.rend());
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("timing: 100000 identical characters", [] {
        string s(100000, 'a');
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("timing: 100000-character palindrome", [] {
        string half;
        mt19937 rng(555);
        for (int k = 0; k < 50000; k++) half += char('a' + rng() % 26);
        string s = half + string(half.rbegin(), half.rend());
        return expectEq(Solution().validPalindrome(s), true);
    });

    T.test("timing: 100000 random letters", [] {
        string s;
        mt19937 rng(31);
        for (int k = 0; k < 100000; k++) s += char('a' + rng() % 26);
        return expectEq(Solution().validPalindrome(s), false);
    });

    return T.summary();
}
