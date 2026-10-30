// Hidden judge for "Minimum Sum of Squared Difference.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Sum of Squared Difference.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums1 = {1,2,3,4};
        vector<int> nums2 = {2,10,20,19};
        int k1 = 0;
        int k2 = 0;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 579LL);
    });

    T.test("Example 2", [] {
        vector<int> nums1 = {1,4,10,12};
        vector<int> nums2 = {5,8,6,9};
        int k1 = 1;
        int k2 = 1;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 43LL);
    });

    T.test("same budget, all of it in k1", [] {
        vector<int> nums1 = {1,4,10,12};
        vector<int> nums2 = {5,8,6,9};
        int k1 = 2;
        int k2 = 0;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 43LL);
    });

    T.test("same budget, all of it in k2", [] {
        vector<int> nums1 = {1,4,10,12};
        vector<int> nums2 = {5,8,6,9};
        int k1 = 0;
        int k2 = 2;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 43LL);
    });

    T.test("single element, no budget", [] {
        vector<int> nums1 = {5};
        vector<int> nums2 = {3};
        int k1 = 0;
        int k2 = 0;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 4LL);
    });

    T.test("single element, budget closes the gap", [] {
        vector<int> nums1 = {5};
        vector<int> nums2 = {3};
        int k1 = 1;
        int k2 = 1;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 0LL);
    });

    T.test("nums1 above nums2", [] {
        vector<int> nums1 = {10};
        vector<int> nums2 = {1};
        int k1 = 0;
        int k2 = 0;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 81LL);
    });

    T.test("arrays already equal", [] {
        vector<int> nums1 = {3,3,3};
        vector<int> nums2 = {3,3,3};
        int k1 = 5;
        int k2 = 5;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 0LL);
    });

    T.test("budget dwarfs the total difference", [] {
        vector<int> nums1 = {1,2,3};
        vector<int> nums2 = {9,9,9};
        int k1 = 1000000000;
        int k2 = 1000000000;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 0LL);
    });

    T.test("budget exactly equals the total difference", [] {
        vector<int> nums1 = {0,0};
        vector<int> nums2 = {3,4};
        int k1 = 7;
        int k2 = 0;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 0LL);
    });

    T.test("budget one short of the total difference", [] {
        vector<int> nums1 = {0,0};
        vector<int> nums2 = {3,4};
        int k1 = 6;
        int k2 = 0;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 1LL);
    });

    T.test("max single difference, no budget", [] {
        vector<int> nums1 = {0};
        vector<int> nums2 = {100000};
        int k1 = 0;
        int k2 = 0;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 10000000000LL);
    });

    T.test("budget left over after levelling", [] {
        vector<int> nums1 = {5,5,5};
        vector<int> nums2 = {0,0,0};
        int k1 = 4;
        int k2 = 0;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 41LL);
    });

    T.test("differences in both directions", [] {
        vector<int> nums1 = {1,10,5};
        vector<int> nums2 = {10,1,5};
        int k1 = 3;
        int k2 = 2;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 85LL);
    });

    T.test("max n, max differences, no budget, largest possible answer (timing check)", [] {
        vector<int> nums1(100000, 0);
        vector<int> nums2(100000, 100000);
        int k1 = 0;
        int k2 = 0;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 1000000000000000LL);
    });

    T.test("max n, max budget in both (k1 + k2 exceeds int) (timing check)", [] {
        vector<int> nums1(100000, 0);
        vector<int> nums2(100000, 100000);
        int k1 = 1000000000;
        int k2 = 1000000000;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 640000000000000LL);
    });

    T.test("max n, budget left over after levelling (timing check)", [] {
        vector<int> nums1(100000, 0);
        vector<int> nums2(100000, 100000);
        int k1 = 1000000001;
        int k2 = 1000000000;
        return expectEq(Solution().minSumSquareDiff(nums1, nums2, k1, k2), 639999999840001LL);
    });

    return T.summary();
}
