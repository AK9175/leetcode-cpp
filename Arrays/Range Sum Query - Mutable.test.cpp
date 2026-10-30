// Hidden judge for "Range Sum Query - Mutable.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Range Sum Query - Mutable.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {1, 3, 5};
        NumArray numArray(nums);
        vector<string> out = {"null"};
        out.push_back(toStr(numArray.sumRange(0, 2)));
        numArray.update(1, 2);
        out.push_back("null");
        out.push_back(toStr(numArray.sumRange(0, 2)));
        return expectEq(out, vector<string>{"null", "9", "null", "8"});
    });

    T.test("single element, updated to the minimum value", [] {
        vector<int> nums = {5};
        NumArray numArray(nums);
        vector<string> out = {"null"};
        out.push_back(toStr(numArray.sumRange(0, 0)));
        numArray.update(0, -100);
        out.push_back("null");
        out.push_back(toStr(numArray.sumRange(0, 0)));
        return expectEq(out, vector<string>{"null", "5", "null", "-100"});
    });

    T.test("all values negative", [] {
        vector<int> nums = {-1, -2, -3, -4};
        NumArray numArray(nums);
        vector<string> out = {"null"};
        out.push_back(toStr(numArray.sumRange(0, 3)));
        out.push_back(toStr(numArray.sumRange(1, 2)));
        numArray.update(2, -100);
        out.push_back("null");
        out.push_back(toStr(numArray.sumRange(0, 3)));
        return expectEq(out, vector<string>{"null", "-10", "-5", "null", "-107"});
    });

    T.test("update writes the same value back", [] {
        vector<int> nums = {1, 2, 3};
        NumArray numArray(nums);
        vector<string> out = {"null"};
        out.push_back(toStr(numArray.sumRange(0, 2)));
        numArray.update(1, 2);
        out.push_back("null");
        out.push_back(toStr(numArray.sumRange(0, 2)));
        return expectEq(out, vector<string>{"null", "6", "null", "6"});
    });

    T.test("single-index ranges after an update", [] {
        vector<int> nums = {7, 8, 9};
        NumArray numArray(nums);
        vector<string> out = {"null"};
        out.push_back(toStr(numArray.sumRange(1, 1)));
        numArray.update(1, -8);
        out.push_back("null");
        out.push_back(toStr(numArray.sumRange(1, 1)));
        out.push_back(toStr(numArray.sumRange(0, 0)));
        out.push_back(toStr(numArray.sumRange(2, 2)));
        return expectEq(out, vector<string>{"null", "8", "null", "-8", "7", "9"});
    });

    T.test("range that excludes the updated index", [] {
        vector<int> nums = {1, 2, 3, 4, 5};
        NumArray numArray(nums);
        vector<string> out = {"null"};
        numArray.update(0, 100);
        out.push_back("null");
        out.push_back(toStr(numArray.sumRange(1, 4)));
        out.push_back(toStr(numArray.sumRange(0, 4)));
        return expectEq(out, vector<string>{"null", "null", "14", "114"});
    });

    T.test("repeated updates to the same index", [] {
        vector<int> nums = {0, 0, 0};
        NumArray numArray(nums);
        vector<string> out = {"null"};
        numArray.update(1, 5);
        numArray.update(1, -5);
        numArray.update(1, 100);
        out.insert(out.end(), {"null", "null", "null"});
        out.push_back(toStr(numArray.sumRange(0, 2)));
        out.push_back(toStr(numArray.sumRange(1, 2)));
        return expectEq(out, vector<string>{"null", "null", "null", "null", "100", "100"});
    });

    T.test("values at both constraint bounds", [] {
        vector<int> nums = {100, -100, 100, -100};
        NumArray numArray(nums);
        vector<string> out = {"null"};
        out.push_back(toStr(numArray.sumRange(0, 3)));
        out.push_back(toStr(numArray.sumRange(0, 1)));
        out.push_back(toStr(numArray.sumRange(0, 0)));
        numArray.update(1, 100);
        out.push_back("null");
        out.push_back(toStr(numArray.sumRange(0, 3)));
        return expectEq(out, vector<string>{"null", "0", "0", "100", "null", "200"});
    });

    T.test("every prefix queried, no updates", [] {
        vector<int> nums = {2, -3, 4, -5, 6};
        NumArray numArray(nums);
        vector<string> out = {"null"};
        for (int right = 0; right < 5; ++right) out.push_back(toStr(numArray.sumRange(0, right)));
        return expectEq(out, vector<string>{"null", "2", "-1", "3", "-2", "4"});
    });

    T.test("every suffix queried after one update", [] {
        vector<int> nums = {1, 1, 1, 1};
        NumArray numArray(nums);
        vector<string> out = {"null"};
        numArray.update(3, 10);
        out.push_back("null");
        for (int left = 3; left >= 0; --left) out.push_back(toStr(numArray.sumRange(left, 3)));
        return expectEq(out, vector<string>{"null", "null", "10", "11", "12", "13"});
    });

    T.test("all zeros", [] {
        vector<int> nums = {0, 0, 0, 0, 0};
        NumArray numArray(nums);
        vector<string> out = {"null"};
        out.push_back(toStr(numArray.sumRange(0, 4)));
        numArray.update(2, 0);
        out.push_back("null");
        out.push_back(toStr(numArray.sumRange(1, 3)));
        return expectEq(out, vector<string>{"null", "0", "null", "0"});
    });

    T.test("max n, whole-array sum after each update (timing check)", [] {
        int n = 30000;
        int ops = 15000;
        vector<int> nums(n, 1);
        NumArray numArray(nums);
        // After the (i+1)-th update the array holds (i+1) twos and the rest ones.
        long long got = 0;
        for (int i = 0; i < ops; ++i) {
            numArray.update(i, 2);
            got += numArray.sumRange(0, n - 1);
        }
        long long expected = (long long)ops * n + (long long)ops * (ops + 1) / 2;
        return expectEq(got, expected);
    });

    T.test("max n, random mixed operations (timing check)", [] {
        mt19937 rng(2024);
        int n = 30000;
        vector<int> nums(n);
        for (int& x : nums) x = (int)(rng() % 201) - 100;
        NumArray numArray(nums);
        long long checksum = 0;  // every sumRange result folded into one number
        for (int i = 0; i < 30000; ++i) {
            if (rng() % 2) {
                numArray.update((int)(rng() % n), (int)(rng() % 201) - 100);
            } else {
                int left = (int)(rng() % n);
                int right = left + (int)(rng() % (n - left));
                checksum += numArray.sumRange(left, right);
            }
        }
        return expectEq(checksum, 20335939LL);
    });

    return T.summary();
}
