// Hidden judge for "Make Array Strictly Increasing.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Make Array Strictly Increasing.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> arr1 = {1, 5, 3, 6, 7};
        vector<int> arr2 = {1, 3, 2, 4};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 1);
    });

    T.test("Example 2", [] {
        vector<int> arr1 = {1, 5, 3, 6, 7};
        vector<int> arr2 = {4, 3, 1};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 2);
    });

    T.test("Example 3, impossible", [] {
        vector<int> arr1 = {1, 5, 3, 6, 7};
        vector<int> arr2 = {1, 6, 3, 3};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), -1);
    });

    T.test("already strictly increasing", [] {
        vector<int> arr1 = {1, 2, 3};
        vector<int> arr2 = {5};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 0);
    });

    T.test("single element is always increasing", [] {
        vector<int> arr1 = {5};
        vector<int> arr2 = {1, 2, 3};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 0);
    });

    T.test("all equal, no usable replacements", [] {
        vector<int> arr1 = {3, 3, 3};
        vector<int> arr2 = {3};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), -1);
    });

    T.test("all equal, fixable with two replacements", [] {
        vector<int> arr1 = {3, 3, 3};
        vector<int> arr2 = {1, 2};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 2);
    });

    T.test("strictly decreasing needs several replacements", [] {
        vector<int> arr1 = {5, 4, 3, 2, 1};
        vector<int> arr2 = {1, 2, 3, 4, 5};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 4);
    });

    T.test("two equal values, only one replacement source", [] {
        vector<int> arr1 = {1, 1};
        vector<int> arr2 = {1};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), -1);
    });

    T.test("duplicate values in arr2 are deduped", [] {
        vector<int> arr1 = {7, 7, 7};
        vector<int> arr2 = {1, 1, 2, 2};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 2);
    });

    T.test("two elements, both replaced from arr2", [] {
        vector<int> arr1 = {1, 0};
        vector<int> arr2 = {0, 1};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 2);
    });

    T.test("small reversed, every element replaced", [] {
        vector<int> arr1 = {4, 3, 2, 1};
        vector<int> arr2 = {1, 2, 3, 4};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 4);
    });

    T.test("small all-identical, all but one replaced", [] {
        vector<int> arr1 = {5, 5, 5, 5, 5, 5};
        vector<int> arr2 = {1, 2, 3, 4, 5, 6};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 5);
    });

    T.test("timing: 2000 reversed, arr2 = 1..n", [] {
        int n = 2000;
        vector<int> arr1(n), arr2(n);
        for (int i = 0; i < n; i++) { arr1[i] = n - i; arr2[i] = i + 1; }
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 2000);
    });

    T.test("timing: 2000 already increasing", [] {
        int n = 2000;
        vector<int> arr1(n);
        for (int i = 0; i < n; i++) arr1[i] = i + 1;
        vector<int> arr2 = {0};
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 0);
    });

    T.test("timing: 2000 all identical, fixable", [] {
        int n = 2000;
        vector<int> arr1(n, 5), arr2(n);
        for (int i = 0; i < n; i++) arr2[i] = i + 1;
        return expectEq(Solution().makeArrayIncreasing(arr1, arr2), 1999);
    });

    return T.summary();
}
