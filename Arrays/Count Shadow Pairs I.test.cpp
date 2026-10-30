// Hidden judge for "Count Shadow Pairs I.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Count Shadow Pairs I.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1,4,4,4,4};
        return expectEq(Solution().shadowPairs(nums), 4LL);
    });

    T.test("Example 2", [] {
        vector<int> nums = {6,7,6,6,7};
        return expectEq(Solution().shadowPairs(nums), 4LL);
    });

    T.test("Example 3", [] {
        vector<int> nums = {1,2,3,4};
        return expectEq(Solution().shadowPairs(nums), 6LL);
    });

    T.test("all equal, no strictly larger partner", [] {
        vector<int> nums = {5,5,5};
        return expectEq(Solution().shadowPairs(nums), 0LL);
    });

    T.test("strictly decreasing", [] {
        vector<int> nums = {3,2,1};
        return expectEq(Solution().shadowPairs(nums), 0LL);
    });

    T.test("smaller value in between blocks the outer pair", [] {
        vector<int> nums = {2,1,3};
        return expectEq(Solution().shadowPairs(nums), 1LL);
    });

    T.test("larger value in between does not block", [] {
        vector<int> nums = {1,3,2};
        return expectEq(Solution().shadowPairs(nums), 2LL);
    });

    T.test("equal value in between does not block", [] {
        vector<int> nums = {2,1,1,2};
        return expectEq(Solution().shadowPairs(nums), 2LL);
    });

    T.test("extreme values", [] {
        vector<int> nums = {1,1000000000,1};
        return expectEq(Solution().shadowPairs(nums), 1LL);
    });

    T.test("big first element, rising tail", [] {
        vector<int> nums = {5,1,2,3,4};
        return expectEq(Solution().shadowPairs(nums), 6LL);
    });

    T.test("repeating low/high pattern", [] {
        vector<int> nums = {1,5,1,5,1,5};
        return expectEq(Solution().shadowPairs(nums), 6LL);
    });

    T.test("alternating dips and peaks", [] {
        vector<int> nums = {4,5,3,6,2,7};
        return expectEq(Solution().shadowPairs(nums), 3LL);
    });

    T.test("max n, strictly increasing (answer exceeds int)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; i++) nums[i] = i + 1;
        return expectEq(Solution().shadowPairs(nums), 4999950000LL);
    });

    T.test("max n, alternating 1 / 1e9", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; i++) nums[i] = i % 2 ? 1000000000 : 1;
        return expectEq(Solution().shadowPairs(nums), 1250025000LL);
    });

    T.test("max n, random values in [1,3]", [] {
        vector<int> nums(100000);
        mt19937 g(7);
        for (auto& x : nums) x = 1 + g() % 3;
        return expectEq(Solution().shadowPairs(nums), 1104097393LL);
    });

    T.test("max n, random values in [1,1e9]", [] {
        vector<int> nums(100000);
        mt19937 g(42);
        for (auto& x : nums) x = 1 + g() % 1000000000;
        return expectEq(Solution().shadowPairs(nums), 995674LL);
    });

    return T.summary();
}
