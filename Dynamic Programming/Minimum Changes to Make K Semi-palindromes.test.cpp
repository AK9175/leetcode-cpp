// Hidden judge for "Minimum Changes to Make K Semi-palindromes.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Changes to Make K Semi-palindromes.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "abcac";
        int k = 2;
        return expectEq(Solution().minimumChanges(s, k), 1);
    });

    T.test("Example 2", [] {
        string s = "abcdef";
        int k = 2;
        return expectEq(Solution().minimumChanges(s, k), 2);
    });

    T.test("Example 3", [] {
        string s = "aabbaa";
        int k = 3;
        return expectEq(Solution().minimumChanges(s, k), 0);
    });

    T.test("whole string, already a semi-palindrome via d=3", [] {
        string s = "abcabc";
        int k = 1;
        return expectEq(Solution().minimumChanges(s, k), 0);
    });

    T.test("shortest semi-palindrome, no changes", [] {
        string s = "aa";
        int k = 1;
        return expectEq(Solution().minimumChanges(s, k), 0);
    });

    T.test("length two needs one change", [] {
        string s = "ab";
        int k = 1;
        return expectEq(Solution().minimumChanges(s, k), 1);
    });

    T.test("whole string is a plain palindrome, d=1", [] {
        string s = "abccba";
        int k = 1;
        return expectEq(Solution().minimumChanges(s, k), 0);
    });

    T.test("all identical letters, any split is free", [] {
        string s = "aaaa";
        int k = 2;
        return expectEq(Solution().minimumChanges(s, k), 0);
    });

    T.test("two length-two parts each need a change", [] {
        string s = "abcd";
        int k = 2;
        return expectEq(Solution().minimumChanges(s, k), 2);
    });

    T.test("repeated pattern split into three parts", [] {
        string s = "abcaabca";
        int k = 3;
        return expectEq(Solution().minimumChanges(s, k), 2);
    });

    T.test("timing: n=200 all 'a', k=100", [] {
        string s(200, 'a');
        int k = 100;
        return expectEq(Solution().minimumChanges(s, k), 0);
    });

    T.test("timing: n=200 random over 4 letters, k=1", [] {
        string s;
        mt19937 r(5);
        for (int i = 0; i < 200; i++) s += (char)('a' + r() % 4);
        int k = 1;
        return expectEq(Solution().minimumChanges(s, k), 64);
    });

    T.test("timing: n=200 random over 4 letters, k=50", [] {
        string s;
        mt19937 r(5);
        for (int i = 0; i < 200; i++) s += (char)('a' + r() % 4);
        int k = 50;
        return expectEq(Solution().minimumChanges(s, k), 13);
    });

    T.test("timing: n=200 random over 4 letters, k=100", [] {
        string s;
        mt19937 r(5);
        for (int i = 0; i < 200; i++) s += (char)('a' + r() % 4);
        int k = 100;
        return expectEq(Solution().minimumChanges(s, k), 79);
    });

    return T.summary();
}
