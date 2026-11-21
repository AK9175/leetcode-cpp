// Hidden judge for "Find Subtree Sizes After Changes.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Find Subtree Sizes After Changes.cpp"

// {size, sum, first, last} fingerprint for large outputs.
static vector<long long> digest(const vector<int>& v) {
    long long sum = 0;
    for (int x : v) sum += x;
    return {(long long)v.size(), sum, v.empty() ? -1 : v.front(), v.empty() ? -1 : v.back()};
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        vector<int> parent = {-1, 0, 0, 1, 1, 1};
        string s = "abaabc";
        return expectEq(Solution().findSubtreeSizes(parent, s), vector<int>{6, 3, 1, 1, 1, 1});
    });

    T.test("Example 2", [] {
        vector<int> parent = {-1, 0, 4, 0, 1};
        string s = "abbba";
        return expectEq(Solution().findSubtreeSizes(parent, s), vector<int>{5, 2, 1, 1, 1});
    });

    T.test("single node", [] {
        vector<int> parent = {-1};
        string s = "a";
        return expectEq(Solution().findSubtreeSizes(parent, s), vector<int>{1});
    });

    T.test("two nodes, same char (parent is already the match)", [] {
        vector<int> parent = {-1, 0};
        string s = "aa";
        return expectEq(Solution().findSubtreeSizes(parent, s), vector<int>{2, 1});
    });

    T.test("two nodes, different char, no change", [] {
        vector<int> parent = {-1, 0};
        string s = "ab";
        return expectEq(Solution().findSubtreeSizes(parent, s), vector<int>{2, 1});
    });

    T.test("chain, all same char stays a chain", [] {
        vector<int> parent = {-1, 0, 1, 2, 3};
        string s = "aaaaa";
        return expectEq(Solution().findSubtreeSizes(parent, s), vector<int>{5, 4, 3, 2, 1});
    });

    T.test("chain, all distinct stays a chain", [] {
        vector<int> parent = {-1, 0, 1, 2, 3};
        string s = "abcde";
        return expectEq(Solution().findSubtreeSizes(parent, s), vector<int>{5, 4, 3, 2, 1});
    });

    T.test("chain abab, two reattachments", [] {
        vector<int> parent = {-1, 0, 1, 2};
        string s = "abab";
        return expectEq(Solution().findSubtreeSizes(parent, s), vector<int>{4, 2, 1, 1});
    });

    T.test("star, all children same char as root", [] {
        vector<int> parent = {-1, 0, 0, 0, 0};
        string s = "aaaaa";
        return expectEq(Solution().findSubtreeSizes(parent, s), vector<int>{5, 1, 1, 1, 1});
    });

    T.test("deeper chain abcab reattaches to the nearest match", [] {
        vector<int> parent = {-1, 0, 1, 2, 3};
        string s = "abcab";
        return expectEq(Solution().findSubtreeSizes(parent, s), vector<int>{5, 3, 1, 1, 1});
    });

    T.test("timing: 100000 chain, all 'a' (unchanged chain)", [] {
        int n = 100000;
        vector<int> parent(n, -1);
        for (int i = 1; i < n; i++) parent[i] = i - 1;
        string s(n, 'a');
        auto got = Solution().findSubtreeSizes(parent, s);
        return expectEq(digest(got), vector<long long>{100000, (long long)100000 * 100001 / 2, 100000, 1});
    });

    T.test("timing: 100000 random tree over 3 letters", [] {
        int n = 100000;
        vector<int> parent(n, -1);
        string s(n, 'a');
        mt19937 rng(1);
        for (int i = 1; i < n; i++) parent[i] = rng() % i;
        for (int i = 0; i < n; i++) s[i] = (char)('a' + rng() % 3);
        auto got = Solution().findSubtreeSizes(parent, s);
        return expectEq(digest(got), vector<long long>{100000, 711013, 100000, 1});
    });

    T.test("timing: 100000 chain, characters cycling a..z", [] {
        int n = 100000;
        vector<int> parent(n, -1);
        for (int i = 1; i < n; i++) parent[i] = i - 1;
        string s(n, 'a');
        for (int i = 0; i < n; i++) s[i] = (char)('a' + (i % 26));
        auto got = Solution().findSubtreeSizes(parent, s);
        return expectEq(digest(got), vector<long long>{100000, 193607650, 100000, 1});
    });

    return T.summary();
}
