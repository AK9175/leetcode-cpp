// Hidden judge for "Maximum Nesting Depth of Two Valid Parentheses Strings.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Maximum Nesting Depth of Two Valid Parentheses Strings.cpp"

// Many answers are accepted, so each test checks the properties the statement asks for
// rather than one fixed array: every character is labelled 0 or 1, each of the two labelled
// subsequences is a VPS, and the deeper of the two reaches exactly `bestDepth` — the
// smallest value any split of that seq can achieve. Each test passes its own bestDepth.
bool isVPS(const string& s) {
    int bal = 0;
    for (char c : s) {
        bal += (c == '(') ? 1 : -1;
        if (bal < 0) return false;
    }
    return bal == 0;
}

int depthOf(const string& s) {
    int bal = 0, mx = 0;
    for (char c : s) {
        bal += (c == '(') ? 1 : -1;
        mx = max(mx, bal);
    }
    return mx;
}

bool isValidSplit(const string& seq, const vector<int>& answer, int bestDepth) {
    if (answer.size() != seq.size()) return false;
    string a, b;
    for (size_t i = 0; i < answer.size(); ++i) {
        if (answer[i] == 0) a += seq[i];
        else if (answer[i] == 1) b += seq[i];
        else return false;
    }
    if (!isVPS(a) || !isVPS(b)) return false;
    return max(depthOf(a), depthOf(b)) == bestDepth;
}

// `times` copies of `unit`, concatenated.
string repeated(const string& unit, int times) {
    string res;
    res.reserve(unit.size() * times);
    for (int i = 0; i < times; ++i) res += unit;
    return res;
}

// A random VPS of length n, drawn from a fixed seed so the test is deterministic.
string randomVPS(int n, unsigned seed) {
    mt19937 rng(seed);
    string seq;
    int open = 0, opensLeft = n / 2, closesLeft = n / 2;
    while (opensLeft || closesLeft) {
        bool canOpen = opensLeft > 0, canClose = open > 0;
        if (canOpen && canClose) {
            if (rng() & 1) { seq += '('; --opensLeft; ++open; }
            else           { seq += ')'; --closesLeft; --open; }
        } else if (canOpen) { seq += '('; --opensLeft; ++open; }
        else                { seq += ')'; --closesLeft; --open; }
    }
    return seq;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string seq = "(()())";
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 1),
                           "two VPS's, deeper one of depth 1");
    });

    T.test("Example 2", [] {
        string seq = "()(())()";
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 1),
                           "two VPS's, deeper one of depth 1");
    });

    T.test("shortest input, a single pair", [] {
        string seq = "()";
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 1),
                           "two VPS's, deeper one of depth 1");
    });

    T.test("one pair inside another", [] {
        string seq = "(())";
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 1),
                           "two VPS's, deeper one of depth 1");
    });

    T.test("three levels of nesting", [] {
        string seq = "((()))";
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 2),
                           "two VPS's, deeper one of depth 2");
    });

    T.test("four pairs side by side", [] {
        string seq = "()()()()";
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 1),
                           "two VPS's, deeper one of depth 1");
    });

    T.test("four levels of nesting", [] {
        string seq = "(((())))";
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 2),
                           "two VPS's, deeper one of depth 2");
    });

    T.test("five levels of nesting, odd depth", [] {
        string seq = "((((()))))";
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 3),
                           "two VPS's, deeper one of depth 3");
    });

    T.test("nesting with a sibling pair inside", [] {
        string seq = "(()(()))";
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 2),
                           "two VPS's, deeper one of depth 2");
    });

    T.test("two nested groups side by side", [] {
        string seq = "(())(())";
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 1),
                           "two VPS's, deeper one of depth 1");
    });

    T.test("deep group followed by a shallow one", [] {
        string seq = "((()))()";
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 2),
                           "two VPS's, deeper one of depth 2");
    });

    T.test("100 levels of nesting, even depth", [] {
        string seq = repeated("(", 100) + repeated(")", 100);
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 50),
                           "two VPS's, deeper one of depth 50");
    });

    T.test("101 levels of nesting, odd depth", [] {
        string seq = repeated("(", 101) + repeated(")", 101);
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 51),
                           "two VPS's, deeper one of depth 51");
    });

    T.test("max length, 5000 pairs side by side (timing)", [] {
        string seq = repeated("()", 5000);
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 1),
                           "two VPS's, deeper one of depth 1");
    });

    T.test("max length, 5000 levels of nesting (timing)", [] {
        string seq = repeated("(", 5000) + repeated(")", 5000);
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 2500),
                           "two VPS's, deeper one of depth 2500");
    });

    T.test("max length, 2500 copies of a depth-two group (timing)", [] {
        string seq = repeated("(())", 2500);
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 1),
                           "two VPS's, deeper one of depth 1");
    });

    T.test("max length, random valid string, fixed seed (timing)", [] {
        string seq = randomVPS(10000, 12345);
        vector<int> answer = Solution().maxDepthAfterSplit(seq);
        return expectValid(answer, isValidSplit(seq, answer, 91),
                           "two VPS's, deeper one of depth 91");
    });

    return T.summary();
}
