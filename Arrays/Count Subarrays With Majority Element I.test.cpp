// Hidden judge for "Count Subarrays With Majority Element I.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Count Subarrays With Majority Element I.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1,2,2,3};
        int target = 2;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 5);
    });

    T.test("Example 2", [] {
        vector<int> nums = {1,1,1,1};
        int target = 1;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 10);
    });

    T.test("Example 3", [] {
        vector<int> nums = {1,2,3};
        int target = 4;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 0);
    });

    T.test("single element equal to target", [] {
        vector<int> nums = {7};
        int target = 7;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 1);
    });

    T.test("single element different from target", [] {
        vector<int> nums = {7};
        int target = 8;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 0);
    });

    T.test("target absent, all elements identical", [] {
        vector<int> nums = {5,5,5};
        int target = 2;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 0);
    });

    T.test("two elements, exact tie is not a majority", [] {
        vector<int> nums = {1,2};
        int target = 2;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 1);
    });

    T.test("lone target surrounded by others", [] {
        vector<int> nums = {1,2,1};
        int target = 2;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 1);
    });

    T.test("every element is the target", [] {
        vector<int> nums(7, 4);
        int target = 4;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 28);
    });

    T.test("alternating target and other, odd length", [] {
        vector<int> nums;
        for (int i = 0; i < 9; ++i) nums.push_back(i % 2 == 0 ? 3 : 8);
        int target = 3;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 15);
    });

    T.test("values at the 1e9 limit", [] {
        vector<int> nums = {1000000000, 999999999, 1000000000};
        int target = 1000000000;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 3);
    });

    T.test("run of targets flanked by others", [] {
        vector<int> nums = {5,3,3,3,5};
        int target = 3;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 11);
    });

    T.test("max n, every element is the target (timing)", [] {
        vector<int> nums(1000, 9);
        int target = 9;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 500500);
    });

    T.test("max n, alternating target and other (timing)", [] {
        vector<int> nums;
        for (int i = 0; i < 1000; ++i) nums.push_back(i % 2 == 0 ? 1 : 2);
        int target = 2;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 125250);
    });

    T.test("max n, block of 400 targets then 600 others (timing)", [] {
        vector<int> nums;
        for (int i = 0; i < 1000; ++i) nums.push_back(i < 400 ? 7 : 1);
        int target = 7;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 160000);
    });

    T.test("max n, random values 1..3, fixed seed (timing)", [] {
        mt19937 rng(12345);
        vector<int> nums(1000);
        for (int& x : nums) x = int(rng() % 3) + 1;
        int target = 2;
        return expectEq(Solution().countMajoritySubarrays(nums, target), 1679);
    });

    return T.summary();
}
