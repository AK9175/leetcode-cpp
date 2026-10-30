// Hidden judge for "Equal Sum Partition After Removing One Element.cpp".
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Equal Sum Partition After Removing One Element.cpp"

// Independent O(n^2) brute force, used only by the randomized stress test below:
// it tries every removal and every split literally, exactly as the statement describes.
// It is deliberately naive and is not the intended solution.
static bool bruteForce(const vector<int>& nums) {
    int n = (int)nums.size();
    for (int r = 0; r < n; ++r) {
        vector<int> rest;
        for (int i = 0; i < n; ++i)
            if (i != r) rest.push_back(nums[i]);
        long long total = 0;
        for (int x : rest) total += x;
        long long left = 0;
        for (int k = 1; k + 1 <= (int)rest.size(); ++k) {
            left += rest[k - 1];
            if (left == total - left) return true;
        }
    }
    return false;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1, 2, 5, 1, 2};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("Example 2", [] {
        vector<int> nums = {1, 2, 3, 4, 6};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("Example 3", [] {
        vector<int> nums = {1, 2, 4};
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("Example 4", [] {
        vector<int> nums = {0, 0, 0};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    // ---- boundary: shortest allowed array ----

    T.test("min length, middle removal works", [] {
        vector<int> nums = {1, 5, 1};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("min length, equal split exists before removal but not after", [] {
        vector<int> nums = {3, -7, -4};
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("min length, first element must go", [] {
        vector<int> nums = {5, 0, 0};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("min length, last element must go", [] {
        vector<int> nums = {0, 0, 5};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("min length, all negative", [] {
        vector<int> nums = {-3, -1, -3};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("min length, all negative, impossible", [] {
        vector<int> nums = {-1, -2, -4};
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("min length, one negative, impossible", [] {
        vector<int> nums = {1, 3, -2};
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("alternating signs summing to zero, impossible", [] {
        vector<int> nums = {3, -2, 3, -4};
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("min length, cancelling extremes, impossible", [] {
        vector<int> nums = {1000000, -1000000, 0};
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    // ---- which index must be removed ----

    T.test("only removing index 0 works", [] {
        vector<int> nums = {-8, -7, 7, 5, 5};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("only removing the last index works", [] {
        vector<int> nums = {7, -5, 4, 6, 1};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("only removing an interior index works", [] {
        vector<int> nums = {8, -3, 0, 3, 8};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("only one interior removal works, all positive", [] {
        vector<int> nums = {5, 2, 6, 2, 10};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    // ---- equal split exists before the removal, but no removal keeps one ----

    T.test("all positive, equal halves before removal, impossible after", [] {
        vector<int> nums = {6, 9, 10, 5};
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("longer positive array, equal split before removal, impossible after", [] {
        vector<int> nums = {2, 4, 2, 11, 7, 11, 11, 4};
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("mixed signs, equal split before removal, impossible after", [] {
        vector<int> nums = {-1, 1, 1, 1};
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("mixed signs with a zero, impossible", [] {
        vector<int> nums = {2, -1, -5, -4, 3, -3};
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("all positive, no removal helps", [] {
        vector<int> nums = {1, 1, 8, 7, 3};
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    // ---- duplicates, zeros, extreme values ----

    T.test("all elements equal, odd count", [] {
        vector<int> nums = {4, 4, 4, 4, 4};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("all zeros", [] {
        vector<int> nums = {0, 0, 0, 0};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("max magnitude values repeated", [] {
        vector<int> nums = {1000000, 1000000, 1000000};
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("min magnitude values plus one positive", [] {
        vector<int> nums = {-1000000, -1000000, -1000000, 1000000};
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("half sums exceed 32 bits", [] {
        vector<int> nums(4999, 1000000);  // halves sum to 2'499'000'000 > INT_MAX
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    // ---- randomized stress test against the brute force ----

    T.test("randomized small arrays vs brute force", [] {
        mt19937 rng(20251022);
        for (int iter = 0; iter < 3000; ++iter) {
            int n = 3 + (int)(rng() % 7);
            vector<int> nums(n);
            for (int& x : nums) x = (int)(rng() % 9) - 4;
            bool expected = bruteForce(nums);
            vector<int> copy = nums;
            bool got = Solution().canPartitionAfterRemoval(copy);
            if (got != expected) {
                ostringstream os;
                os << "nums = " << nums << " -> expected " << boolalpha << expected;
                return CheckResult{false, toStr(got), os.str()};
            }
        }
        return noCheck();
    });

    // ---- constraint-sized timing checks (an O(n^2) scan will not finish these) ----

    T.test("max n, all ones (timing check)", [] {
        vector<int> nums(100000, 1);
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("max n - 1, all ones (timing check)", [] {
        vector<int> nums(99999, 1);
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("max n - 1, every element at the positive limit (timing check)", [] {
        vector<int> nums(99999, 1000000);
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("max n, alternating positive and negative limits (timing check)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; ++i) nums[i] = (i % 2 == 0) ? 1000000 : -1000000;
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("max n, random full range, only 3 removals work (timing check)", [] {
        mt19937 rng(20251022);
        vector<int> nums(100000);
        for (int& x : nums) x = (int)(rng() % 2000001) - 1000000;
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("max n, random values in {-1,0,1} (timing check)", [] {
        mt19937 rng(7);
        vector<int> nums(100000);
        for (int& x : nums) x = (int)(rng() % 3) - 1;
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("max n, strictly increasing 1..100000 (timing check)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; ++i) nums[i] = i + 1;
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("max n, zeros then one positive at the end (timing check)", [] {
        vector<int> nums(100000, 0);
        nums[99999] = 5;
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("max n, one positive at the front then zeros (timing check)", [] {
        vector<int> nums(100000, 0);
        nums[0] = 5;
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    T.test("max n, random positive values, impossible (timing check)", [] {
        mt19937 rng(424242);
        vector<int> nums(100000);
        for (int& x : nums) x = 1 + (int)(rng() % 1000000);
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("max n, strictly decreasing large values, impossible (timing check)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; ++i) nums[i] = 1000000 - i;
        return expectEq(Solution().canPartitionAfterRemoval(nums), false);
    });

    T.test("max n, all zeros (timing check)", [] {
        vector<int> nums(100000, 0);
        return expectEq(Solution().canPartitionAfterRemoval(nums), true);
    });

    return T.summary();
}
