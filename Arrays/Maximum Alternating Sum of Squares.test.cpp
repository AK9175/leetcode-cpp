// Hidden judge for "Maximum Alternating Sum of Squares.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Maximum Alternating Sum of Squares.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1,2,3};
        return expectEq(Solution().maxAlternatingSum(nums), 12LL);
    });

    T.test("Example 2", [] {
        vector<int> nums = {1,-1,2,-2,3,-3};
        return expectEq(Solution().maxAlternatingSum(nums), 16LL);
    });

    T.test("single element", [] {
        vector<int> nums = {5};
        return expectEq(Solution().maxAlternatingSum(nums), 25LL);
    });

    T.test("single zero", [] {
        vector<int> nums = {0};
        return expectEq(Solution().maxAlternatingSum(nums), 0LL);
    });

    T.test("two elements", [] {
        vector<int> nums = {3,4};
        return expectEq(Solution().maxAlternatingSum(nums), 7LL);
    });

    T.test("equal magnitudes, opposite signs", [] {
        vector<int> nums = {-4,4};
        return expectEq(Solution().maxAlternatingSum(nums), 0LL);
    });

    T.test("all equal, even length", [] {
        vector<int> nums = {7,7};
        return expectEq(Solution().maxAlternatingSum(nums), 0LL);
    });

    T.test("all equal, odd length", [] {
        vector<int> nums = {7,7,7};
        return expectEq(Solution().maxAlternatingSum(nums), 49LL);
    });

    T.test("all zeros", [] {
        vector<int> nums = {0,0,0,0};
        return expectEq(Solution().maxAlternatingSum(nums), 0LL);
    });

    T.test("all negative", [] {
        vector<int> nums = {-1,-2,-3};
        return expectEq(Solution().maxAlternatingSum(nums), 12LL);
    });

    T.test("duplicates with one larger value", [] {
        vector<int> nums = {2,2,2,3};
        return expectEq(Solution().maxAlternatingSum(nums), 5LL);
    });

    T.test("single element at max magnitude", [] {
        vector<int> nums = {-40000};
        return expectEq(Solution().maxAlternatingSum(nums), 1600000000LL);
    });

    T.test("tiny input whose answer already exceeds int range", [] {
        vector<int> nums = {40000,40000,0};
        return expectEq(Solution().maxAlternatingSum(nums), 3200000000LL);
    });

    T.test("max n, half at max magnitude and half zero, largest possible answer (timing check)", [] {
        vector<int> nums(100000);
        for (int i = 0; i < 100000; i++) nums[i] = (i < 50000) ? 40000 : 0;
        return expectEq(Solution().maxAlternatingSum(nums), 80000000000000LL);
    });

    T.test("max n, all at max magnitude, even length (timing check)", [] {
        vector<int> nums(100000, 40000);
        return expectEq(Solution().maxAlternatingSum(nums), 0LL);
    });

    T.test("odd max n, all at max magnitude (timing check)", [] {
        vector<int> nums(99999, -40000);
        return expectEq(Solution().maxAlternatingSum(nums), 1600000000LL);
    });

    return T.summary();
}
