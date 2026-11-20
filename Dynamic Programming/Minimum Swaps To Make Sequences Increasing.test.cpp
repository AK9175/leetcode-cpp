// Hidden judge for "Minimum Swaps To Make Sequences Increasing.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Swaps To Make Sequences Increasing.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums1 = {1, 3, 5, 4};
        vector<int> nums2 = {1, 2, 3, 7};
        return expectEq(Solution().minSwap(nums1, nums2), 1);
    });

    T.test("Example 2", [] {
        vector<int> nums1 = {0, 3, 5, 8, 9};
        vector<int> nums2 = {2, 1, 4, 6, 9};
        return expectEq(Solution().minSwap(nums1, nums2), 1);
    });

    T.test("minimum length, already increasing", [] {
        vector<int> nums1 = {1, 2};
        vector<int> nums2 = {3, 4};
        return expectEq(Solution().minSwap(nums1, nums2), 0);
    });

    T.test("minimum length, one swap needed", [] {
        vector<int> nums1 = {3, 2};
        vector<int> nums2 = {1, 4};
        return expectEq(Solution().minSwap(nums1, nums2), 1);
    });

    T.test("identical increasing sequences", [] {
        vector<int> nums1 = {1, 2, 3, 4, 5};
        vector<int> nums2 = {1, 2, 3, 4, 5};
        return expectEq(Solution().minSwap(nums1, nums2), 0);
    });

    T.test("equal values at a position force a choice", [] {
        vector<int> nums1 = {1, 3, 3};
        vector<int> nums2 = {1, 2, 4};
        return expectEq(Solution().minSwap(nums1, nums2), 1);
    });

    T.test("swap only the first pair", [] {
        vector<int> nums1 = {3, 2, 4};
        vector<int> nums2 = {1, 5, 6};
        return expectEq(Solution().minSwap(nums1, nums2), 1);
    });

    T.test("two separate swaps needed", [] {
        vector<int> nums1 = {5, 2, 8, 4};
        vector<int> nums2 = {1, 6, 3, 9};
        return expectEq(Solution().minSwap(nums1, nums2), 2);
    });

    T.test("zeros at the start", [] {
        vector<int> nums1 = {0, 4, 2};
        vector<int> nums2 = {3, 1, 5};
        return expectEq(Solution().minSwap(nums1, nums2), 1);
    });

    T.test("equal mid values, single swap suffices", [] {
        vector<int> nums1 = {1, 2, 4, 5};
        vector<int> nums2 = {2, 3, 3, 5};
        return expectEq(Solution().minSwap(nums1, nums2), 1);
    });

    T.test("timing: 100000 interleaved, no swaps needed", [] {
        int n = 100000;
        vector<int> nums1(n), nums2(n);
        for (int i = 0; i < n; i++) { nums1[i] = 2 * i; nums2[i] = 2 * i + 1; }
        return expectEq(Solution().minSwap(nums1, nums2), 0);
    });

    T.test("timing: 100000 zigzag, every other position swapped", [] {
        int n = 100000;
        vector<int> nums1(n), nums2(n);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { nums1[i] = i;          nums2[i] = i + 100000; }
            else            { nums1[i] = i + 100000; nums2[i] = i;          }
        }
        return expectEq(Solution().minSwap(nums1, nums2), 50000);
    });

    T.test("timing: 100000 feasible-by-construction random", [] {
        int n = 100000;
        vector<int> nums1(n), nums2(n);
        long long va = 0, vb = 0;
        mt19937 r(5);
        for (int i = 0; i < n; i++) { va += 1 + r() % 3; vb += 1 + r() % 3; nums1[i] = (int)va; nums2[i] = (int)vb; }
        for (int i = 0; i < n; i++) if (r() & 1) swap(nums1[i], nums2[i]);
        return expectEq(Solution().minSwap(nums1, nums2), 49965);
    });

    return T.summary();
}
