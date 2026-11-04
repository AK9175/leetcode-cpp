// Hidden judge for "Minimum Operations to Sort With Locked Indices.cpp"
// (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Operations to Sort With Locked Indices.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {2, 1, 3, 4};
        vector<int> locked = {0, 1, 0, 1};
        int k = 1;
        return expectEq(Solution().minOperations(nums, locked, k), 2);
    });

    T.test("Example 2", [] {
        vector<int> nums = {3, 1, 2};
        vector<int> locked = {1, 0, 1};
        int k = 2;
        return expectEq(Solution().minOperations(nums, locked, k), 4);
    });

    T.test("Example 3", [] {
        vector<int> nums = {2, 3, 1};
        vector<int> locked = {1, 0, 0};
        int k = 0;
        return expectEq(Solution().minOperations(nums, locked, k), -1);
    });

    T.test("single element, unlocked", [] {
        vector<int> nums = {1};
        vector<int> locked = {0};
        int k = 0;
        return expectEq(Solution().minOperations(nums, locked, k), 0);
    });

    T.test("single element, locked", [] {
        vector<int> nums = {1};
        vector<int> locked = {1};
        int k = 0;
        return expectEq(Solution().minOperations(nums, locked, k), 0);
    });

    T.test("already sorted with every index locked", [] {
        vector<int> nums = {1, 2, 3, 4};
        vector<int> locked = {1, 1, 1, 1};
        int k = 0;
        return expectEq(Solution().minOperations(nums, locked, k), 0);
    });

    T.test("reverse sorted, nothing locked", [] {
        vector<int> nums = {4, 3, 2, 1};
        vector<int> locked = {0, 0, 0, 0};
        int k = 0;
        return expectEq(Solution().minOperations(nums, locked, k), 6);
    });

    T.test("reverse sorted, all locked, budget exactly enough", [] {
        vector<int> nums = {4, 3, 2, 1};
        vector<int> locked = {1, 1, 1, 1};
        int k = 4;
        return expectEq(Solution().minOperations(nums, locked, k), 10);
    });

    T.test("reverse sorted, all locked, budget one short", [] {
        vector<int> nums = {4, 3, 2, 1};
        vector<int> locked = {1, 1, 1, 1};
        int k = 3;
        return expectEq(Solution().minOperations(nums, locked, k), -1);
    });

    T.test("locked value already in place but something must cross it", [] {
        vector<int> nums = {3, 2, 1};
        vector<int> locked = {0, 1, 0};
        int k = 1;
        return expectEq(Solution().minOperations(nums, locked, k), 4);
    });

    T.test("same board, no unlock budget", [] {
        vector<int> nums = {3, 2, 1};
        vector<int> locked = {0, 1, 0};
        int k = 0;
        return expectEq(Solution().minOperations(nums, locked, k), -1);
    });

    T.test("locked fixed points that may stay locked", [] {
        vector<int> nums = {1, 3, 2, 4};
        vector<int> locked = {1, 0, 0, 1};
        int k = 0;
        return expectEq(Solution().minOperations(nums, locked, k), 1);
    });

    T.test("locked index holding the wrong value", [] {
        vector<int> nums = {1, 3, 2, 4};
        vector<int> locked = {0, 1, 0, 0};
        int k = 0;
        return expectEq(Solution().minOperations(nums, locked, k), -1);
    });

    T.test("unlock budget larger than needed", [] {
        vector<int> nums = {2, 1, 3, 4};
        vector<int> locked = {0, 1, 0, 1};
        int k = 4;
        return expectEq(Solution().minOperations(nums, locked, k), 2);
    });

    T.test("two independent blocks split by a locked separator", [] {
        vector<int> nums = {2, 1, 3, 5, 4, 6};
        vector<int> locked = {0, 0, 1, 0, 0, 1};
        int k = 0;
        return expectEq(Solution().minOperations(nums, locked, k), 2);
    });

    T.test("locked index holds its own value but 6 must cross it", [] {
        vector<int> nums = {4, 1, 6, 3, 5, 2};
        vector<int> locked = {0, 0, 0, 0, 1, 0};
        int k = 1;
        // nums[4] == 5 is already correct, but max(nums[0..4]) == 6, so index 4 must open.
        return expectEq(Solution().minOperations(nums, locked, k), 9);
    });

    T.test("same board with no unlock budget", [] {
        vector<int> nums = {4, 1, 6, 3, 5, 2};
        vector<int> locked = {0, 0, 0, 0, 1, 0};
        int k = 0;
        return expectEq(Solution().minOperations(nums, locked, k), -1);
    });

    T.test("three locked indices, only the middle one may stay", [] {
        vector<int> nums = {3, 2, 1, 4, 6, 7, 5};
        vector<int> locked = {0, 1, 0, 1, 0, 1, 0};
        int k = 2;
        // Index 1 holds its own value but 3 must cross it, index 5 holds the wrong value,
        // index 3 is a clean separator. 5 inversions + 2 unlocks.
        return expectEq(Solution().minOperations(nums, locked, k), 7);
    });

    T.test("same board, budget one short of the two unlocks needed", [] {
        vector<int> nums = {3, 2, 1, 4, 6, 7, 5};
        vector<int> locked = {0, 1, 0, 1, 0, 1, 0};
        int k = 1;
        return expectEq(Solution().minOperations(nums, locked, k), -1);
    });

    T.test("sorted prefix, five locked indices needed, budget of four", [] {
        vector<int> nums = {1, 2, 6, 4, 8, 7, 3, 5};
        vector<int> locked = {0, 0, 1, 0, 1, 1, 1, 1};
        int k = 4;
        // Indices 2, 4, 5, 6, 7 all have to open; four unlocks is one short.
        return expectEq(Solution().minOperations(nums, locked, k), -1);
    });

    T.test("same board with exactly enough budget", [] {
        vector<int> nums = {1, 2, 6, 4, 8, 7, 3, 5};
        vector<int> locked = {0, 0, 1, 0, 1, 1, 1, 1};
        int k = 5;
        // 5 unlocks + 9 inversions.
        return expectEq(Solution().minOperations(nums, locked, k), 14);
    });

    T.test("timing: 2000 reverse sorted, nothing locked", [] {
        int n = 2000;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = n - i;
        vector<int> locked(n, 0);
        int k = 0;
        // Every pair is inverted, so this is n(n-1)/2.
        return expectEq(Solution().minOperations(nums, locked, k), 1999000);
    });

    T.test("timing: 2000 reverse sorted, every index locked", [] {
        int n = 2000;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = n - i;
        vector<int> locked(n, 1);
        int k = 2000;
        // n unlocks plus n(n-1)/2 swaps.
        return expectEq(Solution().minOperations(nums, locked, k), 2001000);
    });

    T.test("timing: 2000 random permutation with random locks", [] {
        int n = 2000;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = i + 1;
        mt19937 rng(5);
        shuffle(nums.begin(), nums.end(), rng);
        vector<int> locked(n);
        for (int i = 0; i < n; i++) locked[i] = (int)(rng() % 2);
        int k = 2000;
        return expectEq(Solution().minOperations(nums, locked, k), 987602);
    });

    T.test("timing: 2000 all locked, only the ends swapped, budget too small", [] {
        int n = 2000;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = i + 1;
        swap(nums[0], nums[n - 1]);
        vector<int> locked(n, 1);
        int k = 1;
        return expectEq(Solution().minOperations(nums, locked, k), -1);
    });

    return T.summary();
}
