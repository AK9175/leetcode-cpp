// Hidden judge for "Count Shadow Pairs II.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Count Shadow Pairs II.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {3,1,4,2,5};
        return expectEq(Solution().shadowPairs(nums), 5);
    });

    T.test("Example 2", [] {
        vector<int> nums = {6,7,8,9};
        return expectEq(Solution().shadowPairs(nums), 3);
    });

    T.test("all equal", [] {
        vector<int> nums = {5,5,5};
        return expectEq(Solution().shadowPairs(nums), 0);
    });

    T.test("strictly decreasing", [] {
        vector<int> nums = {3,2,1};
        return expectEq(Solution().shadowPairs(nums), 0);
    });

    T.test("value strictly between blocks the outer pair", [] {
        vector<int> nums = {1,2,3};
        return expectEq(Solution().shadowPairs(nums), 2);
    });

    T.test("larger value in between does not block", [] {
        vector<int> nums = {1,5,3};
        return expectEq(Solution().shadowPairs(nums), 2);
    });

    T.test("smaller value in between does not block", [] {
        vector<int> nums = {2,1,3};
        return expectEq(Solution().shadowPairs(nums), 2);
    });

    T.test("equal to left value in between does not block", [] {
        vector<int> nums = {1,1,2};
        return expectEq(Solution().shadowPairs(nums), 2);
    });

    T.test("repeated values on both ends", [] {
        vector<int> nums = {2,1,2,1,2};
        return expectEq(Solution().shadowPairs(nums), 3);
    });

    T.test("extreme values, duplicate max", [] {
        vector<int> nums = {1,1000000000,500000000,1000000000};
        return expectEq(Solution().shadowPairs(nums), 3);
    });

    T.test("mixed dips and peaks", [] {
        vector<int> nums = {4,2,6,3,5,1,7};
        return expectEq(Solution().shadowPairs(nums), 8);
    });

    T.test("decreasing run then a new max", [] {
        vector<int> nums = {5,4,3,2,1,6};
        return expectEq(Solution().shadowPairs(nums), 5);
    });

    T.test("max n, strictly increasing", [] {
        vector<int> nums(50000);
        for (int i = 0; i < 50000; i++) nums[i] = i + 1;
        return expectEq(Solution().shadowPairs(nums), 49999);
    });

    T.test("max n, strictly decreasing", [] {
        vector<int> nums(50000);
        for (int i = 0; i < 50000; i++) nums[i] = 50000 - i;
        return expectEq(Solution().shadowPairs(nums), 0);
    });

    T.test("max n, valley (decreasing then increasing)", [] {
        vector<int> nums(50000);
        for (int i = 0; i < 50000; i++) nums[i] = i < 25000 ? 25000 - i : i + 1;
        return expectEq(Solution().shadowPairs(nums), 49999);
    });

    T.test("max n, alternating 1 / 1e9", [] {
        vector<int> nums(50000);
        for (int i = 0; i < 50000; i++) nums[i] = i % 2 ? 1000000000 : 1;
        return expectEq(Solution().shadowPairs(nums), 312512500);
    });

    T.test("max n, random values in [1,3]", [] {
        vector<int> nums(50000);
        mt19937 g(7);
        for (auto& x : nums) x = 1 + g() % 3;
        return expectEq(Solution().shadowPairs(nums), 278182779);
    });

    T.test("max n, random values in [1,100]", [] {
        vector<int> nums(50000);
        mt19937 g(2026);
        for (auto& x : nums) x = 1 + g() % 100;
        return expectEq(Solution().shadowPairs(nums), 12575775);
    });

    T.test("max n, random values in [1,1e9]", [] {
        vector<int> nums(50000);
        mt19937 g(42);
        for (auto& x : nums) x = 1 + g() % 1000000000;
        return expectEq(Solution().shadowPairs(nums), 470075);
    });

    return T.summary();
}
