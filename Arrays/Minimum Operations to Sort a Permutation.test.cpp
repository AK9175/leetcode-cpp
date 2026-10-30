// Hidden judge for "Minimum Operations to Sort a Permutation.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Minimum Operations to Sort a Permutation.cpp"

// Input generators for the big tests.
// ascendingRotated(n, k)[i] = (i + k) % n, i.e. 0..n-1 rotated left k times.
static vector<int> ascendingRotated(int n, int k) {
    vector<int> out(n);
    for (int i = 0; i < n; ++i) out[i] = (i + k) % n;
    return out;
}
// descendingRotated(n, k): n-1..0 rotated left k times.
static vector<int> descendingRotated(int n, int k) {
    vector<int> out(n);
    for (int i = 0; i < n; ++i) out[i] = n - 1 - (i + k) % n;
    return out;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {0, 2, 1};
        return expectEq(Solution().minOperations(nums), 2);
    });

    T.test("Example 2", [] {
        vector<int> nums = {1, 0, 2};
        return expectEq(Solution().minOperations(nums), 2);
    });

    T.test("Example 3", [] {
        vector<int> nums = {2, 0, 1, 3};
        return expectEq(Solution().minOperations(nums), -1);
    });

    T.test("single element", [] {
        vector<int> nums = {0};
        return expectEq(Solution().minOperations(nums), 0);
    });

    T.test("two elements, sorted", [] {
        vector<int> nums = {0, 1};
        return expectEq(Solution().minOperations(nums), 0);
    });

    T.test("two elements, swapped", [] {
        vector<int> nums = {1, 0};
        return expectEq(Solution().minOperations(nums), 1);
    });

    T.test("already sorted, n = 5", [] {
        vector<int> nums = {0, 1, 2, 3, 4};
        return expectEq(Solution().minOperations(nums), 0);
    });

    T.test("fully reversed, n = 5", [] {
        vector<int> nums = {4, 3, 2, 1, 0};
        return expectEq(Solution().minOperations(nums), 1);
    });

    T.test("rotated ascending, zero near the front", [] {
        vector<int> nums = {4, 0, 1, 2, 3};
        return expectEq(Solution().minOperations(nums), 1);
    });

    T.test("rotated ascending, zero at the end", [] {
        vector<int> nums = {1, 2, 3, 4, 0};
        return expectEq(Solution().minOperations(nums), 3);
    });

    T.test("rotated ascending, zero in the middle", [] {
        vector<int> nums = {2, 3, 4, 0, 1};
        return expectEq(Solution().minOperations(nums), 3);
    });

    T.test("zero first, rest descending", [] {
        vector<int> nums = {0, 4, 3, 2, 1};
        return expectEq(Solution().minOperations(nums), 2);
    });

    T.test("rotated descending", [] {
        vector<int> nums = {1, 0, 4, 3, 2};
        return expectEq(Solution().minOperations(nums), 3);
    });

    T.test("four elements, cheapest route takes three operations", [] {
        vector<int> nums = {1, 0, 3, 2};
        return expectEq(Solution().minOperations(nums), 3);
    });

    T.test("one adjacent pair out of place, impossible", [] {
        vector<int> nums = {0, 2, 1, 3, 4};
        return expectEq(Solution().minOperations(nums), -1);
    });

    T.test("max n, already sorted (timing check)", [] {
        vector<int> nums = ascendingRotated(100000, 0);
        return expectEq(Solution().minOperations(nums), 0);
    });

    T.test("max n, fully reversed (timing check)", [] {
        vector<int> nums = descendingRotated(100000, 0);
        return expectEq(Solution().minOperations(nums), 1);
    });

    T.test("max n, rotated ascending by half (timing check)", [] {
        vector<int> nums = ascendingRotated(100000, 50000);
        return expectEq(Solution().minOperations(nums), 50000);
    });

    T.test("max n, rotated descending by half (timing check)", [] {
        vector<int> nums = descendingRotated(100000, 50000);
        return expectEq(Solution().minOperations(nums), 50001);
    });

    T.test("max n, zero at the last index (timing check)", [] {
        vector<int> nums = ascendingRotated(100000, 1);
        return expectEq(Solution().minOperations(nums), 3);
    });

    T.test("max n, impossible (timing check)", [] {
        vector<int> nums = ascendingRotated(100000, 0);
        swap(nums[0], nums[1]);
        return expectEq(Solution().minOperations(nums), -1);
    });

    return T.summary();
}
