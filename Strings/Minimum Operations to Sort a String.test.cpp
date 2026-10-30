// Hidden judge for "Minimum Operations to Sort a String.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Operations to Sort a String.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "dog";
        return expectEq(Solution().minOperations(s), 1);
    });

    T.test("Example 2", [] {
        string s = "card";
        return expectEq(Solution().minOperations(s), 2);
    });

    T.test("Example 3", [] {
        string s = "gf";
        return expectEq(Solution().minOperations(s), -1);
    });

    T.test("single character", [] {
        string s = "a";
        return expectEq(Solution().minOperations(s), 0);
    });

    T.test("already sorted", [] {
        string s = "abc";
        return expectEq(Solution().minOperations(s), 0);
    });

    T.test("every character the same", [] {
        string s = "aaaa";
        return expectEq(Solution().minOperations(s), 0);
    });

    T.test("two characters, in order", [] {
        string s = "ab";
        return expectEq(Solution().minOperations(s), 0);
    });

    T.test("two characters, out of order", [] {
        string s = "ba";
        return expectEq(Solution().minOperations(s), -1);
    });

    T.test("three characters, fully reversed", [] {
        string s = "cba";
        return expectEq(Solution().minOperations(s), 3);
    });

    T.test("smallest only at the end, largest only at the front", [] {
        string s = "zbca";
        return expectEq(Solution().minOperations(s), 3);
    });

    T.test("smallest character sits in the middle", [] {
        string s = "cab";
        return expectEq(Solution().minOperations(s), 2);
    });

    T.test("first character is already the smallest", [] {
        string s = "adcb";
        return expectEq(Solution().minOperations(s), 1);
    });

    T.test("last character is already the largest", [] {
        string s = "bcaz";
        return expectEq(Solution().minOperations(s), 1);
    });

    T.test("two blocks of repeated characters", [] {
        string s = "bbbaaa";
        return expectEq(Solution().minOperations(s), 2);
    });

    T.test("all 26 letters in reverse", [] {
        string s = "zyxwvutsrqponmlkjihgfedcba";
        return expectEq(Solution().minOperations(s), 3);
    });

    T.test("max n, already sorted (timing check)", [] {
        string s;
        for (int i = 0; i < 26; ++i) s += string(3846, (char)('a' + i));
        s += string(100000 - s.size(), 'z');
        return expectEq(Solution().minOperations(s), 0);
    });

    T.test("max n, two descending blocks (timing check)", [] {
        string s = string(50000, 'z') + string(50000, 'a');
        return expectEq(Solution().minOperations(s), 2);
    });

    T.test("max n, smallest only at the end and largest only at the front (timing check)", [] {
        string s = "z" + string(99998, 'm') + "a";
        return expectEq(Solution().minOperations(s), 3);
    });

    T.test("max n, random letters (timing check)", [] {
        mt19937 rng(606);
        string s(100000, 'a');
        for (char& c : s) c = (char)('a' + rng() % 26);
        return expectEq(Solution().minOperations(s), 2);
    });

    return T.summary();
}
