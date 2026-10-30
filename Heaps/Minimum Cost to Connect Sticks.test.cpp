// Hidden judge for "Minimum Cost to Connect Sticks.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Cost to Connect Sticks.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> sticks = {2,4,3};
        return expectEq(Solution().connectSticks(sticks), 14);
    });

    T.test("Example 2", [] {
        vector<int> sticks = {1,8,3,5};
        return expectEq(Solution().connectSticks(sticks), 30);
    });

    T.test("Example 3", [] {
        vector<int> sticks = {5};
        return expectEq(Solution().connectSticks(sticks), 0);
    });

    T.test("single stick of max length", [] {
        vector<int> sticks = {10000};
        return expectEq(Solution().connectSticks(sticks), 0);
    });

    T.test("two sticks, one connection", [] {
        vector<int> sticks = {1,10000};
        return expectEq(Solution().connectSticks(sticks), 10001);
    });

    T.test("all sticks equal", [] {
        vector<int> sticks = {1,1,1,1};
        return expectEq(Solution().connectSticks(sticks), 8);
    });

    T.test("already sorted ascending", [] {
        vector<int> sticks = {1,2,3,4,5};
        return expectEq(Solution().connectSticks(sticks), 33);
    });

    T.test("same sticks reversed, answer must not change", [] {
        vector<int> sticks = {5,4,3,2,1};
        return expectEq(Solution().connectSticks(sticks), 33);
    });

    T.test("one huge stick among tiny ones", [] {
        vector<int> sticks = {1,1,1,10000};
        return expectEq(Solution().connectSticks(sticks), 10008);
    });

    T.test("max lengths, odd count", [] {
        vector<int> sticks = {10000,10000,10000};
        return expectEq(Solution().connectSticks(sticks), 50000);
    });

    T.test("1000 sticks of length 1", [] {
        vector<int> sticks(1000, 1);
        return expectEq(Solution().connectSticks(sticks), 9976);
    });

    T.test("max n, all max length (timing check, largest answer)", [] {
        vector<int> sticks(10000, 10000);
        return expectEq(Solution().connectSticks(sticks), 1336160000);
    });

    T.test("max n, lengths 1..10000 (timing check)", [] {
        vector<int> sticks;
        for (int i = 1; i <= 10000; ++i) sticks.push_back(i);
        return expectEq(Solution().connectSticks(sticks), 652354680);
    });

    T.test("max n, random lengths (timing check)", [] {
        vector<int> sticks;
        mt19937 rng(12345);
        for (int i = 0; i < 10000; ++i) sticks.push_back(rng() % 10000 + 1);
        return expectEq(Solution().connectSticks(sticks), 661261132);
    });

    return T.summary();
}
