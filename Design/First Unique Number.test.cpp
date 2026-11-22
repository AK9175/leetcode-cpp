// Hidden judge for "First Unique Number.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "First Unique Number.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> nums = {2, 3, 5};
        FirstUnique firstUnique(nums);
        vector<string> out = {"null"};
        out.push_back(toStr(firstUnique.showFirstUnique()));
        firstUnique.add(5);
        out.push_back("null");
        out.push_back(toStr(firstUnique.showFirstUnique()));
        firstUnique.add(2);
        out.push_back("null");
        out.push_back(toStr(firstUnique.showFirstUnique()));
        firstUnique.add(3);
        out.push_back("null");
        out.push_back(toStr(firstUnique.showFirstUnique()));
        return expectEq(out, vector<string>{"null", "2", "null", "2", "null", "3", "null", "-1"});
    });

    T.test("Example 2", [] {
        vector<int> nums = {7, 7, 7, 7, 7, 7};
        FirstUnique firstUnique(nums);
        vector<string> out = {"null", toStr(firstUnique.showFirstUnique())};
        firstUnique.add(7);
        firstUnique.add(3);
        firstUnique.add(3);
        firstUnique.add(7);
        firstUnique.add(17);
        out.insert(out.end(), {"null", "null", "null", "null", "null"});
        out.push_back(toStr(firstUnique.showFirstUnique()));
        return expectEq(out, vector<string>{"null", "-1", "null", "null", "null", "null", "null", "17"});
    });

    T.test("Example 3", [] {
        vector<int> nums = {809};
        FirstUnique firstUnique(nums);
        vector<string> out = {"null", toStr(firstUnique.showFirstUnique())};
        firstUnique.add(809);
        out.push_back("null");
        out.push_back(toStr(firstUnique.showFirstUnique()));
        return expectEq(out, vector<string>{"null", "809", "null", "-1"});
    });

    T.test("initial values are all unique", [] {
        vector<int> nums = {4, 8, 15};
        FirstUnique firstUnique(nums);
        return expectEq(firstUnique.showFirstUnique(), 4);
    });

    T.test("new value becomes the first unique", [] {
        vector<int> nums = {5, 5, 6, 6};
        FirstUnique firstUnique(nums);
        firstUnique.add(7);
        return expectEq(firstUnique.showFirstUnique(), 7);
    });

    T.test("duplicate later unique value removes it", [] {
        vector<int> nums = {10, 20, 30};
        FirstUnique firstUnique(nums);
        firstUnique.add(10);
        return expectEq(firstUnique.showFirstUnique(), 20);
    });

    T.test("order of unique values is preserved", [] {
        vector<int> nums = {4, 5, 6};
        FirstUnique firstUnique(nums);
        firstUnique.add(4);
        firstUnique.add(6);
        return expectEq(firstUnique.showFirstUnique(), 5);
    });

    T.test("all values remain duplicated", [] {
        vector<int> nums = {1, 2, 1, 2};
        FirstUnique firstUnique(nums);
        firstUnique.add(1);
        firstUnique.add(2);
        return expectEq(firstUnique.showFirstUnique(), -1);
    });

    T.test("maximum initial stream with first value unique", [] {
        vector<int> nums;
        for (int value = 1; value <= 100000; value++) nums.push_back(value);
        FirstUnique firstUnique(nums);
        return expectEq(firstUnique.showFirstUnique(), 1);
    });

    T.test("maximum initial stream after duplicating the first value", [] {
        vector<int> nums;
        for (int value = 1; value <= 100000; value++) nums.push_back(value);
        FirstUnique firstUnique(nums);
        firstUnique.add(1);
        return expectEq(firstUnique.showFirstUnique(), 2);
    });

    T.test("empty initial stream then add makes a unique", [] {
        vector<int> nums = {};
        FirstUnique firstUnique(nums);
        vector<int> out = {firstUnique.showFirstUnique()};   // -1, nothing yet
        firstUnique.add(42);
        out.push_back(firstUnique.showFirstUnique());         // 42
        return expectEq(out, vector<int>{-1, 42});
    });

    T.test("third occurrence does not resurrect uniqueness", [] {
        vector<int> nums = {1, 2};
        FirstUnique firstUnique(nums);                        // first unique: 1
        firstUnique.add(1);                                   // 1 -> duplicate, first unique: 2
        firstUnique.add(1);                                   // 1 seen 3x, still not unique
        firstUnique.add(2);                                   // 2 -> duplicate, none unique
        return expectEq(firstUnique.showFirstUnique(), -1);
    });

    T.test("repeated showFirstUnique is idempotent", [] {
        vector<int> nums = {9, 9, 4, 4, 7};
        FirstUnique firstUnique(nums);                        // only 7 is unique
        vector<int> out = {firstUnique.showFirstUnique(),
                           firstUnique.showFirstUnique()};    // calling twice must not mutate state
        return expectEq(out, vector<int>{7, 7});
    });

    T.test("duplicate among added values removes it", [] {
        vector<int> nums = {5};
        FirstUnique firstUnique(nums);                        // first unique: 5
        firstUnique.add(6);                                   // unique: 5, 6 -> first 5
        firstUnique.add(5);                                   // 5 duplicate -> first 6
        firstUnique.add(6);                                   // 6 duplicate -> none
        return expectEq(firstUnique.showFirstUnique(), -1);
    });

    T.test("unique sits after a long run of duplicates in init", [] {
        vector<int> nums = {3, 3, 3, 3, 5, 3};                // 3 appears 5x, 5 once
        FirstUnique firstUnique(nums);
        return expectEq(firstUnique.showFirstUnique(), 5);
    });

    T.test("large values within constraints", [] {
        vector<int> nums = {100000000, 100000000, 99999999};  // only 99999999 is unique
        FirstUnique firstUnique(nums);
        return expectEq(firstUnique.showFirstUnique(), 99999999);
    });

    T.test("long interleaved sequence of adds", [] {
        vector<int> nums = {1, 2, 3, 4};
        FirstUnique firstUnique(nums);                        // first unique: 1
        firstUnique.add(2);                                   // 2 dup -> first 1
        firstUnique.add(1);                                   // 1 dup -> first 3
        firstUnique.add(5);                                   // unique append -> first 3
        vector<int> out = {firstUnique.showFirstUnique()};    // 3
        firstUnique.add(3);                                   // 3 dup -> first 4
        firstUnique.add(4);                                   // 4 dup -> first 5
        firstUnique.add(5);                                   // 5 dup -> none
        out.push_back(firstUnique.showFirstUnique());         // -1
        return expectEq(out, vector<int>{3, -1});
    });

    return T.summary();
}
