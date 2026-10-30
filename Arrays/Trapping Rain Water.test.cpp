// Hidden judge for "Trapping Rain Water.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Trapping Rain Water.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
        return expectEq(Solution().trap(height), 6);
    });

    T.test("Example 2", [] {
        vector<int> height = {4,2,0,3,2,5};
        return expectEq(Solution().trap(height), 9);
    });

    T.test("single bar", [] {
        vector<int> height = {0};
        return expectEq(Solution().trap(height), 0);
    });

    T.test("two bars", [] {
        vector<int> height = {1,2};
        return expectEq(Solution().trap(height), 0);
    });

    T.test("every bar zero", [] {
        vector<int> height = {0,0,0,0};
        return expectEq(Solution().trap(height), 0);
    });

    T.test("strictly increasing", [] {
        vector<int> height = {1,2,3,4,5};
        return expectEq(Solution().trap(height), 0);
    });

    T.test("strictly decreasing", [] {
        vector<int> height = {5,4,3,2,1};
        return expectEq(Solution().trap(height), 0);
    });

    T.test("one pit between equal walls", [] {
        vector<int> height = {5,0,5};
        return expectEq(Solution().trap(height), 5);
    });

    T.test("shorter wall caps the water", [] {
        vector<int> height = {4,2,3};
        return expectEq(Solution().trap(height), 1);
    });

    T.test("wide flat pit", [] {
        vector<int> height = {3,0,0,0,3};
        return expectEq(Solution().trap(height), 9);
    });

    T.test("V shape, water on both slopes", [] {
        vector<int> height = {5,4,3,2,1,2,3,4,5};
        return expectEq(Solution().trap(height), 16);
    });

    T.test("tall peak splits two basins", [] {
        vector<int> height = {3,0,3,10,3,0,3};
        return expectEq(Solution().trap(height), 6);
    });

    T.test("descending staircase with gaps", [] {
        vector<int> height = {0,5,0,4,0,3,0,2,0,1};
        return expectEq(Solution().trap(height), 10);
    });

    T.test("max heights, single pit", [] {
        vector<int> height = {100000,0,100000};
        return expectEq(Solution().trap(height), 100000);
    });

    T.test("max n, max walls over a flat floor (timing check)", [] {
        vector<int> height(20000, 0);
        height.front() = 100000;
        height.back() = 100000;
        return expectEq(Solution().trap(height), 1999800000);   // (n-2) * 1e5, just under INT_MAX
    });

    T.test("max n, alternating max and zero (timing check)", [] {
        vector<int> height(20000);
        for (int i = 0; i < 20000; i++) height[i] = (i % 2 ? 0 : 100000);
        return expectEq(Solution().trap(height), 999900000);    // 9999 pits * 1e5
    });

    return T.summary();
}
