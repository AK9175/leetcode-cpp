// Hidden judge for "Minimize the Maximum Value of GCD-Connected Array.cpp"
// (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimize the Maximum Value of GCD-Connected Array.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        int n = 4;
        int index = 2;
        int value = 8;
        return expectEq(Solution().minimumMaxValue(n, index, value), 10LL);
    });

    T.test("Example 2", [] {
        int n = 2;
        int index = 1;
        int value = 3;
        return expectEq(Solution().minimumMaxValue(n, index, value), -1LL);
    });

    T.test("Example 3", [] {
        int n = 2;
        int index = 0;
        int value = 3;
        return expectEq(Solution().minimumMaxValue(n, index, value), 6LL);
    });

    T.test("value is 1, nothing can connect to it", [] {
        int n = 5;
        int index = 2;
        int value = 1;
        return expectEq(Solution().minimumMaxValue(n, index, value), -1LL);
    });

    T.test("smallest possible value, at the front", [] {
        int n = 2;
        int index = 0;
        int value = 2;
        return expectEq(Solution().minimumMaxValue(n, index, value), 4LL);
    });

    T.test("smallest possible value, needing a predecessor", [] {
        int n = 2;
        int index = 1;
        int value = 2;
        return expectEq(Solution().minimumMaxValue(n, index, value), -1LL);
    });

    T.test("value at the last index, room on the left exactly fits", [] {
        int n = 3;
        int index = 2;
        int value = 6;
        return expectEq(Solution().minimumMaxValue(n, index, value), 6LL);
    });

    T.test("value at the last index, room on the left one short", [] {
        int n = 3;
        int index = 2;
        int value = 4;
        return expectEq(Solution().minimumMaxValue(n, index, value), -1LL);
    });

    T.test("a prime anywhere but the front is hopeless", [] {
        int n = 5;
        int index = 1;
        int value = 999999937;
        return expectEq(Solution().minimumMaxValue(n, index, value), -1LL);
    });

    T.test("large prime at the front", [] {
        int n = 2;
        int index = 0;
        int value = 999999937;
        return expectEq(Solution().minimumMaxValue(n, index, value), 1999999874LL);
    });

    T.test("power of two with a deep index", [] {
        int n = 1000000;
        int index = 100;
        int value = 1048576;
        return expectEq(Solution().minimumMaxValue(n, index, value), 3048374LL);
    });

    T.test("odd composite with a deep index", [] {
        int n = 1000;
        int index = 100;
        int value = 999;
        return expectEq(Solution().minimumMaxValue(n, index, value), 2798LL);
    });

    T.test("deepest feasible index at max n", [] {
        int n = 1000000000;
        int index = 499999999;
        int value = 1000000000;
        return expectEq(Solution().minimumMaxValue(n, index, value), 2000000000LL);
    });

    T.test("one index deeper, now infeasible", [] {
        int n = 1000000000;
        int index = 500000000;
        int value = 1000000000;
        return expectEq(Solution().minimumMaxValue(n, index, value), -1LL);
    });

    T.test("max n with the largest prime at the front", [] {
        int n = 1000000000;
        int index = 0;
        int value = 999999937;
        // 3999999870 does not fit in a 32-bit int.
        return expectEq(Solution().minimumMaxValue(n, index, value), 3999999870LL);
    });

    T.test("nothing to the right of value", [] {
        int n = 10;
        int index = 9;
        int value = 1000;
        return expectEq(Solution().minimumMaxValue(n, index, value), 1000LL);
    });

    T.test("nothing to the right of an odd value", [] {
        int n = 2;
        int index = 1;
        int value = 9;
        return expectEq(Solution().minimumMaxValue(n, index, value), 9LL);
    });

    T.test("nothing to the right, odd value with a large prime factor", [] {
        int n = 2;
        int index = 1;
        int value = 25;
        return expectEq(Solution().minimumMaxValue(n, index, value), 25LL);
    });

    T.test("nothing to the right, but the left cannot be built", [] {
        int n = 5;
        int index = 4;
        int value = 9;
        // Four elements must fit below 9 ending on one sharing a factor with 9,
        // so at most 6 - but 2,4,6,8 is the tightest chain and 8 shares nothing with 9.
        return expectEq(Solution().minimumMaxValue(n, index, value), -1LL);
    });

    T.test("nothing to the right, left cannot be built, larger value", [] {
        int n = 12;
        int index = 11;
        int value = 25;
        return expectEq(Solution().minimumMaxValue(n, index, value), -1LL);
    });

    return T.summary();
}
