// Hidden judge for "Two Sum.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Two Sum.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        return expectAnyOrder(Solution().twoSum(nums, target), vector<int>{0, 1});
    });

    T.test("Example 2", [] {
        vector<int> nums = {3, 2, 4};
        int target = 6;
        return expectAnyOrder(Solution().twoSum(nums, target), vector<int>{1, 2});
    });

    T.test("Example 3", [] {
        vector<int> nums = {3, 3};
        int target = 6;
        return expectAnyOrder(Solution().twoSum(nums, target), vector<int>{0, 1});
    });

    T.test("negative values", [] {
        vector<int> nums = {-3, 4, 3, 90};
        int target = 0;
        return expectAnyOrder(Solution().twoSum(nums, target), vector<int>{0, 2});
    });

    T.test("negative target", [] {
        vector<int> nums = {-10, -4, -7, 2};
        int target = -5;
        return expectAnyOrder(Solution().twoSum(nums, target), vector<int>{2, 3});
    });

    T.test("duplicate values are required", [] {
        vector<int> nums = {5, 1, 5};
        int target = 10;
        return expectAnyOrder(Solution().twoSum(nums, target), vector<int>{0, 2});
    });

    T.test("solution uses the last element", [] {
        vector<int> nums = {1, 4, 6, 8};
        int target = 9;
        return expectAnyOrder(Solution().twoSum(nums, target), vector<int>{0, 3});
    });

    T.test("values near integer limits", [] {
        vector<int> nums = {1000000000, -1000000000, 7, -3};
        int target = -999999993;
        return expectAnyOrder(Solution().twoSum(nums, target), vector<int>{1, 2});
    });

    T.test("large input, answer at the end", [] {
        vector<int> nums(10000, 1);
        nums[9998] = 123456789;
        nums[9999] = -123456788;
        int target = 1;
        return expectAnyOrder(Solution().twoSum(nums, target), vector<int>{9998, 9999});
    });

    return T.summary();
}
