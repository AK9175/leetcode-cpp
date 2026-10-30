// Hidden judge for "Count Days Spent Together.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Count Days Spent Together.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string arriveAlice = "08-15";
        string leaveAlice = "08-18";
        string arriveBob = "08-16";
        string leaveBob = "08-19";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 3);
    });

    T.test("Example 2", [] {
        string arriveAlice = "10-01";
        string leaveAlice = "10-31";
        string arriveBob = "11-01";
        string leaveBob = "12-31";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 0);
    });

    T.test("identical stays", [] {
        string arriveAlice = "06-10";
        string leaveAlice = "06-20";
        string arriveBob = "06-10";
        string leaveBob = "06-20";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 11);
    });

    T.test("Alice's stay inside Bob's", [] {
        string arriveAlice = "07-10";
        string leaveAlice = "07-12";
        string arriveBob = "07-01";
        string leaveBob = "07-31";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 3);
    });

    T.test("Bob's stay inside Alice's", [] {
        string arriveAlice = "03-01";
        string leaveAlice = "03-31";
        string arriveBob = "03-15";
        string leaveBob = "03-17";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 3);
    });

    T.test("overlap only on Alice's last day", [] {
        string arriveAlice = "08-15";
        string leaveAlice = "08-18";
        string arriveBob = "08-18";
        string leaveBob = "08-25";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 1);
    });

    T.test("overlap only on Alice's first day", [] {
        string arriveAlice = "08-15";
        string leaveAlice = "08-18";
        string arriveBob = "08-01";
        string leaveBob = "08-15";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 1);
    });

    T.test("Bob leaves the day before Alice arrives", [] {
        string arriveAlice = "08-15";
        string leaveAlice = "08-18";
        string arriveBob = "08-01";
        string leaveBob = "08-14";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 0);
    });

    T.test("both stay a single day, the same day", [] {
        string arriveAlice = "05-05";
        string leaveAlice = "05-05";
        string arriveBob = "05-05";
        string leaveBob = "05-05";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 1);
    });

    T.test("both stay a single day, adjacent days", [] {
        string arriveAlice = "05-05";
        string leaveAlice = "05-05";
        string arriveBob = "05-06";
        string leaveBob = "05-06";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 0);
    });

    T.test("whole year for both", [] {
        string arriveAlice = "01-01";
        string leaveAlice = "12-31";
        string arriveBob = "01-01";
        string leaveBob = "12-31";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 365);
    });

    T.test("across the end of February", [] {
        string arriveAlice = "02-25";
        string leaveAlice = "03-05";
        string arriveBob = "02-28";
        string leaveBob = "03-01";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 2);
    });

    T.test("first day of the year only", [] {
        string arriveAlice = "01-01";
        string leaveAlice = "01-01";
        string arriveBob = "01-01";
        string leaveBob = "12-31";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 1);
    });

    T.test("last day of the year only", [] {
        string arriveAlice = "12-31";
        string leaveAlice = "12-31";
        string arriveBob = "01-01";
        string leaveBob = "12-31";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 1);
    });

    T.test("Bob's stay entirely before Alice's", [] {
        string arriveAlice = "11-01";
        string leaveAlice = "12-31";
        string arriveBob = "10-01";
        string leaveBob = "10-31";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 0);
    });

    T.test("Bob's stay ends months before Alice's begins", [] {
        string arriveAlice = "10-20";
        string leaveAlice = "12-22";
        string arriveBob = "06-21";
        string leaveBob = "07-05";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 0);
    });

    T.test("long overlap spanning several months", [] {
        string arriveAlice = "02-14";
        string leaveAlice = "11-20";
        string arriveBob = "05-01";
        string leaveBob = "08-31";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 123);
    });

    T.test("single-day overlap at a month boundary", [] {
        string arriveAlice = "01-31";
        string leaveAlice = "02-01";
        string arriveBob = "02-01";
        string leaveBob = "02-28";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 1);
    });

    T.test("single-day overlap at a 30-day month boundary", [] {
        string arriveAlice = "04-30";
        string leaveAlice = "05-01";
        string arriveBob = "04-29";
        string leaveBob = "04-30";
        return expectEq(Solution().countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob), 1);
    });

    return T.summary();
}
