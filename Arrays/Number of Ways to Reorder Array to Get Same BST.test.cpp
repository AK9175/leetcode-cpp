// Hidden judge for "Number of Ways to Reorder Array to Get Same BST.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Number of Ways to Reorder Array to Get Same BST.cpp"

// Input generator: level-order listing of a perfectly balanced BST over 1..n.
// Inserting in this order gives the shortest possible tree for n values.
static vector<int> balancedLevelOrder(int n) {
    vector<int> out;
    queue<pair<int, int>> q;
    q.push({1, n});
    while (!q.empty()) {
        auto [lo, hi] = q.front();
        q.pop();
        if (lo > hi) continue;
        int mid = (lo + hi) / 2;
        out.push_back(mid);
        q.push({lo, mid - 1});
        q.push({mid + 1, hi});
    }
    return out;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {2, 1, 3};
        return expectEq(Solution().numOfWays(nums), 1);
    });

    T.test("Example 2", [] {
        vector<int> nums = {3, 4, 5, 1, 2};
        return expectEq(Solution().numOfWays(nums), 5);
    });

    T.test("Example 3", [] {
        vector<int> nums = {1, 2, 3};
        return expectEq(Solution().numOfWays(nums), 0);
    });

    T.test("single element", [] {
        vector<int> nums = {1};
        return expectEq(Solution().numOfWays(nums), 0);
    });

    T.test("two elements, ascending", [] {
        vector<int> nums = {1, 2};
        return expectEq(Solution().numOfWays(nums), 0);
    });

    T.test("two elements, descending", [] {
        vector<int> nums = {2, 1};
        return expectEq(Solution().numOfWays(nums), 0);
    });

    T.test("strictly decreasing, n = 5", [] {
        vector<int> nums = {5, 4, 3, 2, 1};
        return expectEq(Solution().numOfWays(nums), 0);
    });

    T.test("root with a left subtree only", [] {
        vector<int> nums = {3, 1, 2};
        return expectEq(Solution().numOfWays(nums), 0);
    });

    T.test("perfectly balanced, n = 7", [] {
        vector<int> nums = {4, 2, 6, 1, 3, 5, 7};
        return expectEq(Solution().numOfWays(nums), 79);
    });

    T.test("lopsided subtrees, n = 7", [] {
        vector<int> nums = {4, 1, 3, 2, 6, 5, 7};
        return expectEq(Solution().numOfWays(nums), 39);
    });

    T.test("nine values in no particular shape", [] {
        vector<int> nums = {5, 9, 2, 7, 1, 8, 3, 6, 4};
        return expectEq(Solution().numOfWays(nums), 419);
    });

    T.test("perfectly balanced, n = 15", [] {
        vector<int> nums = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
        return expectEq(Solution().numOfWays(nums), 21964799);
    });

    T.test("max n, ascending chain (timing check)", [] {
        vector<int> nums(1000);
        for (int i = 0; i < 1000; ++i) nums[i] = i + 1;
        return expectEq(Solution().numOfWays(nums), 0);
    });

    T.test("max n, descending chain (timing check)", [] {
        vector<int> nums(1000);
        for (int i = 0; i < 1000; ++i) nums[i] = 1000 - i;
        return expectEq(Solution().numOfWays(nums), 0);
    });

    T.test("max n, perfectly balanced (timing check)", [] {
        vector<int> nums = balancedLevelOrder(1000);
        return expectEq(Solution().numOfWays(nums), 718156653);
    });

    T.test("max n, random permutation (timing check)", [] {
        vector<int> nums(1000);
        for (int i = 0; i < 1000; ++i) nums[i] = i + 1;
        mt19937 rng(31337);
        shuffle(nums.begin(), nums.end(), rng);
        return expectEq(Solution().numOfWays(nums), 705262840);
    });

    return T.summary();
}
