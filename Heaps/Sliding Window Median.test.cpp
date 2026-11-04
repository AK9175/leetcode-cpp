// Hidden judge for "Sliding Window Median.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Sliding Window Median.cpp"

// The medians are doubles, so compare element-wise within the 1e-5 tolerance the
// statement allows, rather than by exact printed form.
static CheckResult closeVec(const vector<double>& got, const vector<double>& expected,
                            double eps = 1e-5) {
    bool ok = got.size() == expected.size();
    for (size_t i = 0; ok && i < got.size(); i++)
        if (fabs(got[i] - expected[i]) > eps) ok = false;
    return {ok, toStr(got), toStr(expected)};
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
        int k = 3;
        return closeVec(Solution().medianSlidingWindow(nums, k),
                        {1.0, -1.0, -1.0, 3.0, 5.0, 6.0});
    });

    T.test("Example 2", [] {
        vector<int> nums = {1, 2, 3, 4, 2, 3, 1, 4, 2};
        int k = 3;
        return closeVec(Solution().medianSlidingWindow(nums, k),
                        {2.0, 3.0, 3.0, 3.0, 2.0, 3.0, 2.0});
    });

    T.test("single element, k = 1", [] {
        vector<int> nums = {5};
        int k = 1;
        return closeVec(Solution().medianSlidingWindow(nums, k), {5.0});
    });

    T.test("k = 1 echoes every element", [] {
        vector<int> nums = {3, 1, 2};
        int k = 1;
        return closeVec(Solution().medianSlidingWindow(nums, k), {3.0, 1.0, 2.0});
    });

    T.test("whole array is the only window, odd size", [] {
        vector<int> nums = {4, 1, 3, 2, 5};
        int k = 5;
        return closeVec(Solution().medianSlidingWindow(nums, k), {3.0});
    });

    T.test("whole array is the only window, even size", [] {
        vector<int> nums = {4, 1, 3, 2};
        int k = 4;
        return closeVec(Solution().medianSlidingWindow(nums, k), {2.5});
    });

    T.test("even window of size 2", [] {
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        int k = 2;
        return closeVec(Solution().medianSlidingWindow(nums, k),
                        {1.5, 2.5, 3.5, 4.5, 5.5});
    });

    T.test("even window of size 4", [] {
        vector<int> nums = {1, 4, 2, 3, 5, 8, 7};
        int k = 4;
        return closeVec(Solution().medianSlidingWindow(nums, k), {2.5, 3.5, 4.0, 6.0});
    });

    T.test("all elements equal", [] {
        vector<int> nums = {7, 7, 7, 7, 7};
        int k = 3;
        return closeVec(Solution().medianSlidingWindow(nums, k), {7.0, 7.0, 7.0});
    });

    T.test("duplicates straddling the middle", [] {
        vector<int> nums = {1, 1, 2, 2, 3, 3};
        int k = 4;
        return closeVec(Solution().medianSlidingWindow(nums, k), {1.5, 2.0, 2.5});
    });

    T.test("all negative", [] {
        vector<int> nums = {-5, -1, -3, -2, -4};
        int k = 3;
        return closeVec(Solution().medianSlidingWindow(nums, k), {-3.0, -2.0, -3.0});
    });

    T.test("two INT_MAX values average without overflow", [] {
        vector<int> nums = {2147483647, 2147483647};
        int k = 2;
        return closeVec(Solution().medianSlidingWindow(nums, k), {2147483647.0});
    });

    T.test("INT_MIN neighbours average without overflow", [] {
        vector<int> nums = {-2147483648, -2147483647, -2147483646};
        int k = 2;
        return closeVec(Solution().medianSlidingWindow(nums, k),
                        {-2147483647.5, -2147483646.5});
    });

    T.test("INT_MAX and INT_MIN in the same window", [] {
        vector<int> nums = {2147483647, -2147483648, 2147483647, -2147483648};
        int k = 2;
        return closeVec(Solution().medianSlidingWindow(nums, k), {-0.5, -0.5, -0.5});
    });

    T.test("timing: 100000 elements, k = 1 (closed form)", [] {
        int n = 100000;
        vector<int> nums(n);
        mt19937 rng(1);
        for (auto& x : nums) x = (int)rng();
        vector<double> expected(nums.begin(), nums.end());
        return closeVec(Solution().medianSlidingWindow(nums, 1), expected);
    });

    T.test("timing: 100000 alternating extremes, k = 2 (all -0.5)", [] {
        int n = 100000;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = (i & 1) ? 2147483647 : -2147483648;
        vector<double> expected(n - 1, -0.5);
        return closeVec(Solution().medianSlidingWindow(nums, 2), expected);
    });

    T.test("timing: 100000 elements, k = 50000", [] {
        int n = 100000;
        vector<int> nums(n);
        mt19937 rng(2);
        for (auto& x : nums) x = (int)(rng() % 1000000) - 500000;
        auto r = Solution().medianSlidingWindow(nums, 50000);
        return expectEq((int)r.size(), 50001);  // timing check; just confirm the shape
    });

    T.test("timing: 100000 elements, k = n is one window", [] {
        int n = 100000;
        vector<int> nums(n);
        mt19937 rng(3);
        for (auto& x : nums) x = (int)rng();
        auto r = Solution().medianSlidingWindow(nums, n);
        return expectClose(r.at(0), 906670.5);
    });

    return T.summary();
}
