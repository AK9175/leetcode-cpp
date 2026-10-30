// Hidden judge for "Maximize Sum of Squares of Digits.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Maximize Sum of Squares of Digits.cpp"

// Used only by the last test, whose answer is 100000 characters long. It checks the
// statement's requirements rather than working the answer out: `wantScore` is given.
// The tie-break rule ("return the maximum one") is covered by the small tests instead.
static bool isGoodAnswer(const string& got, int num, int sum, long long wantScore) {
    if ((int)got.size() != num) return false;
    if (got[0] == '0') return false;                   // must genuinely have num digits
    long long s = 0, sc = 0;
    for (char c : got) {
        if (c < '0' || c > '9') return false;
        s += c - '0';
        sc += (long long)(c - '0') * (c - '0');
    }
    return s == sum && sc == wantScore;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        int num = 2;
        int sum = 3;
        return expectEq(Solution().maxSumOfSquares(num, sum), string("30"));
    });

    T.test("Example 2", [] {
        int num = 2;
        int sum = 17;
        return expectEq(Solution().maxSumOfSquares(num, sum), string("98"));
    });

    T.test("Example 3", [] {
        int num = 1;
        int sum = 10;
        return expectEq(Solution().maxSumOfSquares(num, sum), string(""));
    });

    T.test("one digit, smallest sum", [] {
        int num = 1;
        int sum = 1;
        return expectEq(Solution().maxSumOfSquares(num, sum), string("1"));
    });

    T.test("one digit, largest possible sum", [] {
        int num = 1;
        int sum = 9;
        return expectEq(Solution().maxSumOfSquares(num, sum), string("9"));
    });

    T.test("two digits, smallest sum", [] {
        int num = 2;
        int sum = 1;
        return expectEq(Solution().maxSumOfSquares(num, sum), string("10"));
    });

    T.test("two digits, largest possible sum", [] {
        int num = 2;
        int sum = 18;
        return expectEq(Solution().maxSumOfSquares(num, sum), string("99"));
    });

    T.test("two digits, sum one over the maximum", [] {
        int num = 2;
        int sum = 19;
        return expectEq(Solution().maxSumOfSquares(num, sum), string(""));
    });

    T.test("three digits, smallest sum", [] {
        int num = 3;
        int sum = 1;
        return expectEq(Solution().maxSumOfSquares(num, sum), string("100"));
    });

    T.test("three digits, largest possible sum", [] {
        int num = 3;
        int sum = 27;
        return expectEq(Solution().maxSumOfSquares(num, sum), string("999"));
    });

    T.test("three digits, sum leaves a remainder", [] {
        int num = 3;
        int sum = 20;
        return expectEq(Solution().maxSumOfSquares(num, sum), string("992"));
    });

    T.test("five digits, sum just past nine", [] {
        int num = 5;
        int sum = 10;
        return expectEq(Solution().maxSumOfSquares(num, sum), string("91000"));
    });

    T.test("six digits, sum a multiple of nine", [] {
        int num = 6;
        int sum = 45;
        return expectEq(Solution().maxSumOfSquares(num, sum), string("999990"));
    });

    T.test("max num, smallest sum, only one good integer (timing check)", [] {
        int num = 200000;
        int sum = 1;
        return expectEq(Solution().maxSumOfSquares(num, sum), "1" + string(199999, '0'));
    });

    T.test("max num, largest possible sum, every digit forced (timing check)", [] {
        int num = 200000;
        int sum = 1800000;                             // 9 * num
        return expectEq(Solution().maxSumOfSquares(num, sum), string(200000, '9'));
    });

    T.test("max num, sum one over the maximum (timing check)", [] {
        int num = 200000;
        int sum = 1800001;
        return expectEq(Solution().maxSumOfSquares(num, sum), string(""));
    });

    T.test("large num, mid-range sum, checked by score (timing check)", [] {
        int num = 100000;
        int sum = 450007;
        string got = Solution().maxSumOfSquares(num, sum);
        return expectValid(got.size(), isGoodAnswer(got, num, sum, 4050049),
                           "100000 digits summing to 450007 with score 4050049");
    });

    return T.summary();
}
