// Hidden judge for "Valid Triangle Number.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Valid Triangle Number.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {2,2,3,4};
        return expectEq(Solution().triangleNumber(nums), 3);
    });

    T.test("Example 2", [] {
        vector<int> nums = {4,2,3,4};
        return expectEq(Solution().triangleNumber(nums), 4);
    });

    T.test("single side", [] {
        vector<int> nums = {5};
        return expectEq(Solution().triangleNumber(nums), 0);
    });

    T.test("two sides", [] {
        vector<int> nums = {3,4};
        return expectEq(Solution().triangleNumber(nums), 0);
    });

    T.test("three sides, two of them sum to the third", [] {
        vector<int> nums = {1,2,3};
        return expectEq(Solution().triangleNumber(nums), 0);
    });

    T.test("three sides, right triangle", [] {
        vector<int> nums = {3,4,5};
        return expectEq(Solution().triangleNumber(nums), 1);
    });

    T.test("all sides zero", [] {
        vector<int> nums = {0,0,0,0};
        return expectEq(Solution().triangleNumber(nums), 0);
    });

    T.test("one zero among equal sides", [] {
        vector<int> nums = {0,1,1,1};
        return expectEq(Solution().triangleNumber(nums), 1);
    });

    T.test("two zeros among usable sides", [] {
        vector<int> nums = {0,0,2,2,3};
        return expectEq(Solution().triangleNumber(nums), 1);
    });

    T.test("all sides equal", [] {
        vector<int> nums = {1,1,1,1};
        return expectEq(Solution().triangleNumber(nums), 4);
    });

    T.test("fibonacci sides, none valid", [] {
        vector<int> nums = {1,1,2,3,5,8,13};
        return expectEq(Solution().triangleNumber(nums), 0);
    });

    T.test("input in descending order", [] {
        vector<int> nums = {10,9,8,7,6,5,4,3,2,1};
        return expectEq(Solution().triangleNumber(nums), 50);
    });

    T.test("max side lengths", [] {
        vector<int> nums = {1000,1000,1000};
        return expectEq(Solution().triangleNumber(nums), 1);
    });

    T.test("thinnest valid triangle", [] {
        vector<int> nums = {1,1000,1000};
        return expectEq(Solution().triangleNumber(nums), 1);
    });

    T.test("max n, distinct sides 1..1000 (timing check)", [] {
        vector<int> nums(1000);
        for (int i = 0; i < 1000; i++) nums[i] = i + 1;
        return expectEq(Solution().triangleNumber(nums), 82958750);
    });

    T.test("max n, every side 1000, largest possible answer (timing check)", [] {
        vector<int> nums(1000, 1000);
        return expectEq(Solution().triangleNumber(nums), 166167000);   // C(1000,3)
    });

    return T.summary();
}
