// Hidden judge for "Number of Sub-arrays With Odd Sum.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Number of Sub-arrays With Odd Sum.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> arr = {1, 3, 5};
        return expectEq(Solution().numOfSubarrays(arr), 4);
    });

    T.test("Example 2", [] {
        vector<int> arr = {2, 4, 6};
        return expectEq(Solution().numOfSubarrays(arr), 0);
    });

    T.test("Example 3", [] {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
        return expectEq(Solution().numOfSubarrays(arr), 16);
    });

    T.test("single odd element", [] {
        vector<int> arr = {5};
        return expectEq(Solution().numOfSubarrays(arr), 1);
    });

    T.test("single even element", [] {
        vector<int> arr = {2};
        return expectEq(Solution().numOfSubarrays(arr), 0);
    });

    T.test("all even, no odd-sum subarray", [] {
        vector<int> arr = {2, 2, 2, 2};
        return expectEq(Solution().numOfSubarrays(arr), 0);
    });

    T.test("all odd values", [] {
        vector<int> arr = {1, 1, 1, 1};
        return expectEq(Solution().numOfSubarrays(arr), 6);
    });

    T.test("even values that are large", [] {
        vector<int> arr = {100, 100, 100};
        return expectEq(Solution().numOfSubarrays(arr), 0);
    });

    T.test("alternating odd and even", [] {
        vector<int> arr = {1, 2, 1, 2, 1};
        return expectEq(Solution().numOfSubarrays(arr), 9);
    });

    T.test("timing: 100000 all-odd, count overflows int before modulo", [] {
        vector<int> arr(100000, 1);
        return expectEq(Solution().numOfSubarrays(arr), 500049986);
    });

    T.test("timing: 100000 all-even is zero", [] {
        vector<int> arr(100000, 2);
        return expectEq(Solution().numOfSubarrays(arr), 0);
    });

    T.test("timing: 100000 random values in [1,100]", [] {
        vector<int> arr(100000);
        mt19937 rng(1);
        for (auto& x : arr) x = 1 + (int)(rng() % 100);
        return expectEq(Solution().numOfSubarrays(arr), 499883930);
    });

    T.test("timing: 100000 alternating even/odd", [] {
        vector<int> arr(100000);
        for (int i = 0; i < 100000; i++) arr[i] = (i % 2) ? 1 : 2;
        return expectEq(Solution().numOfSubarrays(arr), 500049986);
    });

    return T.summary();
}
