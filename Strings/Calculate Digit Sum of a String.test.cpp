// Hidden judge for "Calculate Digit Sum of a String.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Calculate Digit Sum of a String.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string s = "11111222223";
        int k = 3;
        return expectEq(Solution().digitSum(s, k), "135");
    });

    T.test("Example 2", [] {
        string s = "00000000";
        int k = 3;
        return expectEq(Solution().digitSum(s, k), "000");
    });

    T.test("length already equals k, no round", [] {
        string s = "999";
        int k = 3;
        return expectEq(Solution().digitSum(s, k), "999");
    });

    T.test("length already less than k, no round", [] {
        string s = "5";
        int k = 3;
        return expectEq(Solution().digitSum(s, k), "5");
    });

    T.test("single digit with k = 2", [] {
        string s = "7";
        int k = 2;
        return expectEq(Solution().digitSum(s, k), "7");
    });

    T.test("one round lands exactly at length k", [] {
        string s = "123456";
        int k = 3;
        return expectEq(Solution().digitSum(s, k), "615");
    });

    T.test("group sum is multi-digit", [] {
        string s = "999";
        int k = 2;
        return expectEq(Solution().digitSum(s, k), "99");
    });

    T.test("stops when length drops below k", [] {
        string s = "10101010";
        int k = 4;
        return expectEq(Solution().digitSum(s, k), "22");
    });

    T.test("several rounds, k = 3", [] {
        string s = "22211345691211334562";
        int k = 3;
        return expectEq(Solution().digitSum(s, k), "36");
    });

    T.test("timing: 100 nines, k = 2", [] {
        string s(100, '9');
        int k = 2;
        return expectEq(Solution().digitSum(s, k), "99");
    });

    T.test("timing: 100 nines, k = 3", [] {
        string s(100, '9');
        int k = 3;
        return expectEq(Solution().digitSum(s, k), "324");
    });

    T.test("timing: 100 zeros, k = 2", [] {
        string s(100, '0');
        int k = 2;
        return expectEq(Solution().digitSum(s, k), "00");
    });

    return T.summary();
}
