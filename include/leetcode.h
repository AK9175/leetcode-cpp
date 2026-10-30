// Local-only LeetCode prelude. Force-included by run.sh and IntelliSense,
// so solution files can be written exactly as on LeetCode (no #includes needed).
#pragma once

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------------------
// LeetCode's node types (identical definitions)
// ---------------------------------------------------------------------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ---------------------------------------------------------------------------
// Builders: turn LeetCode test inputs into structures
// ---------------------------------------------------------------------------

// makeList({1,2,3})  ->  1 -> 2 -> 3
inline ListNode* makeList(const vector<int>& vals) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : vals) tail = tail->next = new ListNode(v);
    return dummy.next;
}

// makeTree("[3,9,20,null,null,15,7]")  -- paste the LeetCode input string directly
inline TreeNode* makeTree(const string& s) {
    vector<optional<int>> vals;
    string tok;
    for (char c : s) {
        if (c == '[' || c == ' ') continue;
        if (c == ',' || c == ']') {
            if (!tok.empty()) vals.push_back(tok == "null" ? nullopt : optional<int>(stoi(tok)));
            tok.clear();
        } else {
            tok += c;
        }
    }
    if (vals.empty() || !vals[0]) return nullptr;

    TreeNode* root = new TreeNode(*vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    for (size_t i = 1; i < vals.size() && !q.empty(); q.pop()) {
        TreeNode* node = q.front();
        if (i < vals.size() && vals[i]) q.push(node->left = new TreeNode(*vals[i]));
        i++;
        if (i < vals.size() && vals[i]) q.push(node->right = new TreeNode(*vals[i]));
        i++;
    }
    return root;
}

// ---------------------------------------------------------------------------
// Printing: cout/cerr << any vector, set, map, pair, stack, queue, list, tree
// ---------------------------------------------------------------------------
template <typename R>
concept PrintableRange = ranges::range<R> && !is_convertible_v<const R&, string_view>;

// Declarations first so nested types (vector<pair<...>>, map<int, vector<int>>) resolve.
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p);
template <PrintableRange R> ostream& operator<<(ostream& os, const R& r);
template <typename T, typename C> ostream& operator<<(ostream& os, stack<T, C> s);
template <typename T, typename C> ostream& operator<<(ostream& os, queue<T, C> q);
template <typename T, typename C, typename Cmp> ostream& operator<<(ostream& os, priority_queue<T, C, Cmp> pq);

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template <PrintableRange R>
ostream& operator<<(ostream& os, const R& r) {
    os << '[';
    bool first = true;
    for (const auto& x : r) {
        if (!first) os << ", ";
        os << x;
        first = false;
    }
    return os << ']';
}

// Adapters are taken by value (copied) so printing doesn't consume them.
template <typename T, typename C>
ostream& operator<<(ostream& os, stack<T, C> s) {  // printed top -> bottom
    vector<T> v;
    for (; !s.empty(); s.pop()) v.push_back(s.top());
    return os << "stack" << v;
}

template <typename T, typename C>
ostream& operator<<(ostream& os, queue<T, C> q) {  // printed front -> back
    vector<T> v;
    for (; !q.empty(); q.pop()) v.push_back(q.front());
    return os << "queue" << v;
}

template <typename T, typename C, typename Cmp>
ostream& operator<<(ostream& os, priority_queue<T, C, Cmp> pq) {  // printed in pop order
    vector<T> v;
    for (; !pq.empty(); pq.pop()) v.push_back(pq.top());
    return os << "pq" << v;
}

inline ostream& operator<<(ostream& os, ListNode* head) {
    if (!head) return os << "null";
    for (ListNode* cur = head; cur; cur = cur->next) {
        os << cur->val;
        if (cur->next) os << " -> ";
    }
    return os;
}

// Prints in LeetCode's level-order format: [3,9,20,null,null,15,7]
inline ostream& operator<<(ostream& os, TreeNode* root) {
    vector<string> out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (!node) {
            out.push_back("null");
            continue;
        }
        out.push_back(to_string(node->val));
        q.push(node->left);
        q.push(node->right);
    }
    while (!out.empty() && out.back() == "null") out.pop_back();
    os << '[';
    for (size_t i = 0; i < out.size(); i++) os << (i ? "," : "") << out[i];
    return os << ']';
}

// ---------------------------------------------------------------------------
// dbg(x, y, ...) -> prints "[L42] x, y = 5 | [1, 2, 3]" to stderr
// Remove dbg() calls before submitting; it only exists locally.
// ---------------------------------------------------------------------------
template <typename... Ts>
void dbg_impl(int line, const char* names, const Ts&... args) {
    cerr << "\033[33m[L" << line << "] " << names << " = ";
    const char* sep = "";
    ((cerr << sep << args, sep = " | "), ...);
    cerr << "\033[0m\n";
}
#define dbg(...) dbg_impl(__LINE__, #__VA_ARGS__, __VA_ARGS__)

// ---------------------------------------------------------------------------
// Test harness (plays the role of LeetCode's hidden judge)
//
//   TestRunner T;                       // or TestRunner T(3) to run only test #3
//   T.test("Example 1", [] {
//       vector<int> nums = {2,7,11,15};
//       return expectEq(Solution().twoSum(nums, 9), vector<int>{0,1});
//   });
//   return T.summary();
// ---------------------------------------------------------------------------
template <typename T>
string toStr(const T& x) {
    ostringstream os;
    os << boolalpha << x;
    return os.str();
}

struct CheckResult {
    bool ok;
    string got, expected;
};

// Compares printed forms, so it works for ints, vectors, strings, ListNode*, TreeNode*...
template <typename G, typename E>
CheckResult expectEq(const G& got, const E& expected) {
    string g = toStr(got), e = toStr(expected);
    return {g == e, g, e};
}

// "Return the answer in any order": sorts the outer container before comparing.
template <typename T>
CheckResult expectAnyOrder(vector<T> got, vector<T> expected) {
    sort(got.begin(), got.end());
    sort(expected.begin(), expected.end());
    return expectEq(got, expected);
}

// Any order at both levels, e.g. groupAnagrams / 3Sum / subsets.
template <typename T>
CheckResult expectAnyOrderDeep(vector<vector<T>> got, vector<vector<T>> expected) {
    for (auto& v : got) sort(v.begin(), v.end());
    for (auto& v : expected) sort(v.begin(), v.end());
    return expectAnyOrder(std::move(got), std::move(expected));
}

// Floating-point answers ("answers within 1e-5 of the actual answer are accepted").
inline CheckResult expectClose(double got, double expected, double eps = 1e-5) {
    return {fabs(got - expected) <= eps, toStr(got), toStr(expected)};
}

// Several valid answers exist and they can be enumerated.
template <typename G, typename E>
CheckResult expectOneOf(const G& got, const vector<E>& valid) {
    string g = toStr(got);
    for (const auto& v : valid)
        if (g == toStr(v)) return {true, g, toStr(valid)};
    return {false, g, "one of " + toStr(valid)};
}

// Many valid answers: validate with a custom predicate instead.
template <typename G>
CheckResult expectValid(const G& got, bool valid, const string& rule) {
    return {valid, toStr(got), rule};
}

// Only measures runtime (large, constraint-sized inputs). Note: local build is -O0 +
// sanitizers, so it runs several times slower than LeetCode's judge.
inline CheckResult noCheck() { return {true, "(not checked)", "(not checked)"}; }

class TestRunner {
    int only_, index_ = 0, passed_ = 0, failed_ = 0;

public:
    // Pass a test number, or set the TEST environment variable (the editor buttons do this).
    explicit TestRunner(int only = 0) : only_(only) {
        if (!only_) if (const char* env = getenv("TEST")) only_ = atoi(env);
    }

    template <typename F>
    void test(const string& name, F&& body) {
        ++index_;
        if (only_ && index_ != only_) return;
        auto start = chrono::steady_clock::now();
        CheckResult r = body();
        auto ms = chrono::duration<double, milli>(chrono::steady_clock::now() - start).count();
        (r.ok ? passed_ : failed_)++;
        cout << (r.ok ? "\033[32m  PASS " : "\033[31m  FAIL ") << "\033[0m#" << index_ << ' ' << name
             << "  \033[90m(" << fixed << setprecision(1) << ms << " ms)\033[0m\n";
        if (!r.ok) {
            cout << "       expected: " << r.expected << "\n"
                 << "       got:      " << r.got << "\n";
        }
        cout.unsetf(ios::floatfield);
    }

    int summary() const {
        cout << "\n" << (failed_ ? "\033[31m" : "\033[32m") << passed_ << "/" << passed_ + failed_
             << " passed\033[0m\n";
        return failed_ ? 1 : 0;
    }
};
