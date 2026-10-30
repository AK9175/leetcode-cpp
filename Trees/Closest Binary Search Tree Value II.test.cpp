// Hidden judge for "Closest Binary Search Tree Value II.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Closest Binary Search Tree Value II.cpp"

// Builds a perfectly balanced BST over the sorted values in [lo, hi].
static TreeNode* buildBalanced(const vector<int>& sorted, int lo, int hi) {
    if (lo > hi) return nullptr;
    int mid = lo + (hi - lo) / 2;
    return new TreeNode(sorted[mid], buildBalanced(sorted, lo, mid - 1),
                        buildBalanced(sorted, mid + 1, hi));
}

// Builds a right-leaning chain holding first, first+1, ..., first+count-1.
static TreeNode* buildAscendingChain(int first, int count) {
    TreeNode* head = new TreeNode(first);
    TreeNode* cur = head;
    for (int i = 1; i < count; i++) {
        cur->right = new TreeNode(first + i);
        cur = cur->right;
    }
    return head;
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        TreeNode* root = makeTree("[4,2,5,1,3]");
        double target = 3.714286;
        int k = 2;
        return expectAnyOrder(Solution().closestKValues(root, target, k), vector<int>{4, 3});
    });

    T.test("Example 2", [] {
        TreeNode* root = makeTree("[1]");
        double target = 0.000000;
        int k = 1;
        return expectAnyOrder(Solution().closestKValues(root, target, k), vector<int>{1});
    });

    T.test("k equals node count, whole tree", [] {
        TreeNode* root = makeTree("[4,2,5,1,3]");
        double target = 3.714286;
        int k = 5;
        return expectAnyOrder(Solution().closestKValues(root, target, k),
                              vector<int>{1, 2, 3, 4, 5});
    });

    T.test("single node, target far away", [] {
        TreeNode* root = makeTree("[8]");
        double target = 1000000000.0;
        int k = 1;
        return expectAnyOrder(Solution().closestKValues(root, target, k), vector<int>{8});
    });

    T.test("target below every value", [] {
        TreeNode* root = makeTree("[8,4,12,2,6,10,14]");
        double target = -1000000000.0;
        int k = 3;
        return expectAnyOrder(Solution().closestKValues(root, target, k), vector<int>{2, 4, 6});
    });

    T.test("target above every value", [] {
        TreeNode* root = makeTree("[8,4,12,2,6,10,14]");
        double target = 1000000000.0;
        int k = 3;
        return expectAnyOrder(Solution().closestKValues(root, target, k),
                              vector<int>{10, 12, 14});
    });

    T.test("target sits just past a leaf value", [] {
        TreeNode* root = makeTree("[8,4,12,2,6,10,14]");
        double target = 10.4;
        int k = 3;
        return expectAnyOrder(Solution().closestKValues(root, target, k),
                              vector<int>{8, 10, 12});
    });

    T.test("k = 1, nearest single value", [] {
        TreeNode* root = makeTree("[8,4,12,2,6,10,14]");
        double target = 5.4;
        int k = 1;
        return expectAnyOrder(Solution().closestKValues(root, target, k), vector<int>{6});
    });

    T.test("left-leaning chain", [] {
        TreeNode* root = makeTree("[5,4,null,3,null,2,null,1]");
        double target = 2.2;
        int k = 3;
        return expectAnyOrder(Solution().closestKValues(root, target, k), vector<int>{1, 2, 3});
    });

    T.test("right-leaning chain", [] {
        TreeNode* root = makeTree("[1,null,2,null,3,null,4,null,5]");
        double target = 4.9;
        int k = 2;
        return expectAnyOrder(Solution().closestKValues(root, target, k), vector<int>{4, 5});
    });

    T.test("values near 10^9", [] {
        TreeNode* root =
            makeTree("[999999998,999999996,1000000000,null,999999997,999999999]");
        double target = 999999998.4;
        int k = 3;
        return expectAnyOrder(Solution().closestKValues(root, target, k),
                              vector<int>{999999997, 999999998, 999999999});
    });

    T.test("k = 1, the value below target is the closer one", [] {
        TreeNode* root = makeTree("[1,null,32]");
        double target = 11.88;
        int k = 1;
        return expectAnyOrder(Solution().closestKValues(root, target, k), vector<int>{1});
    });

    T.test("window lies entirely below target", [] {
        TreeNode* root = makeTree("[10,9,26]");
        double target = 11.61;
        int k = 2;
        return expectAnyOrder(Solution().closestKValues(root, target, k), vector<int>{9, 10});
    });

    T.test("k = 3, whole window sits below a distant upper neighbour", [] {
        TreeNode* root = makeTree("[8,2,11,null,null,null,38]");
        double target = 17.67;
        int k = 3;
        return expectAnyOrder(Solution().closestKValues(root, target, k),
                              vector<int>{2, 8, 11});
    });

    T.test("k = 6, only the largest value is excluded", [] {
        TreeNode* root = makeTree("[5,3,11,0,4,7,39]");
        double target = 12.11;
        int k = 6;
        return expectAnyOrder(Solution().closestKValues(root, target, k),
                              vector<int>{0, 3, 4, 5, 7, 11});
    });

    T.test("max n balanced tree, target below all (timing check)", [] {
        vector<int> sorted;
        for (int i = 0; i < 10000; i++) sorted.push_back(2 * i);
        TreeNode* root = buildBalanced(sorted, 0, (int)sorted.size() - 1);
        double target = -1000000000.0;
        int k = 100;
        vector<int> expected;
        for (int i = 0; i < k; i++) expected.push_back(2 * i);
        return expectAnyOrder(Solution().closestKValues(root, target, k), expected);
    });

    T.test("max n chain, window in the middle (timing check)", [] {
        TreeNode* root = buildAscendingChain(0, 10000);
        double target = 5000.4;
        int k = 10;
        vector<int> expected;
        for (int v = 4996; v <= 5005; v++) expected.push_back(v);
        return expectAnyOrder(Solution().closestKValues(root, target, k), expected);
    });

    return T.summary();
}
