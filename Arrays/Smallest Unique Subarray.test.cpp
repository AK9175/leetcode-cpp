// Hidden judge for "Smallest Unique Subarray.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Smallest Unique Subarray.cpp"

int main() {
    TestRunner T;

    T.test("Example 1: all values equal", [] {
        vector<int> nums = {3, 3, 3};
        return expectEq(Solution().smallestUniqueSubarray(nums), 3);
    });

    T.test("Example 2: one unique value", [] {
        vector<int> nums = {2, 1, 2, 3, 3};
        return expectEq(Solution().smallestUniqueSubarray(nums), 1);
    });

    T.test("Example 3: unique subarray starts at length two", [] {
        vector<int> nums = {1, 1, 2, 2, 1};
        return expectEq(Solution().smallestUniqueSubarray(nums), 2);
    });

    T.test("single element", [] {
        vector<int> nums = {42};
        return expectEq(Solution().smallestUniqueSubarray(nums), 1);
    });

    T.test("two different values", [] {
        vector<int> nums = {1, 2};
        return expectEq(Solution().smallestUniqueSubarray(nums), 1);
    });

    T.test("two equal values", [] {
        vector<int> nums = {5, 5};
        return expectEq(Solution().smallestUniqueSubarray(nums), 2);
    });

    T.test("all values equal, longer array", [] {
        vector<int> nums = {7, 7, 7, 7};
        return expectEq(Solution().smallestUniqueSubarray(nums), 4);
    });

    T.test("alternating values", [] {
        vector<int> nums = {1, 2, 1, 2};
        return expectEq(Solution().smallestUniqueSubarray(nums), 2);
    });

    T.test("repeated full pattern", [] {
        vector<int> nums = {1, 2, 3, 1, 2, 3};
        return expectEq(Solution().smallestUniqueSubarray(nums), 2);
    });

    T.test("unique value after repeated values", [] {
        vector<int> nums = {4, 4, 4, 2, 4};
        return expectEq(Solution().smallestUniqueSubarray(nums), 1);
    });

    T.test("maximum length all equal timing check", [] {
        vector<int> nums(100000, 9);
        return expectEq(Solution().smallestUniqueSubarray(nums), 100000);
    });

    T.test("maximum length repeated alternating timing check", [] {
        vector<int> nums;
        nums.reserve(100000);
        for (int i = 0; i < 50000; i++) {
            nums.push_back(1);
            nums.push_back(2);
        }
        return expectEq(Solution().smallestUniqueSubarray(nums), 99998);
    });

    return T.summary();
}
