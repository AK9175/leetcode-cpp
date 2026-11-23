// Hidden judge for "Diagonal Traversal of Binary Tree.cpp".
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
struct Node {
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

#include "Diagonal Traversal of Binary Tree.cpp"

static Node* node(int value) {
    return new Node(value);
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        Node* root = node(8);
        root->left = node(3);
        root->right = node(10);
        root->left->left = node(1);
        root->right->left = node(6);
        root->right->right = node(14);
        root->right->right->left = node(13);
        root->right->left->left = node(4);
        root->right->left->right = node(7);
        return expectEq(Solution().diagonal(root), vector<int>{8, 10, 14, 3, 6, 7, 13, 1, 4});
    });

    T.test("Example 2: left chain", [] {
        Node* root = node(1);
        root->left = node(2);
        root->left->left = node(3);
        return expectEq(Solution().diagonal(root), vector<int>{1, 2, 3});
    });

    T.test("empty tree", [] {
        Node* root = nullptr;
        return expectEq(Solution().diagonal(root), vector<int>{});
    });

    T.test("single node", [] {
        Node* root = node(42);
        return expectEq(Solution().diagonal(root), vector<int>{42});
    });

    T.test("right chain stays on one diagonal", [] {
        Node* root = node(1);
        root->right = node(2);
        root->right->right = node(3);
        root->right->right->right = node(4);
        return expectEq(Solution().diagonal(root), vector<int>{1, 2, 3, 4});
    });

    T.test("left and right children", [] {
        Node* root = node(1);
        root->left = node(2);
        root->right = node(3);
        return expectEq(Solution().diagonal(root), vector<int>{1, 3, 2});
    });

    T.test("mixed branches preserve diagonal order", [] {
        Node* root = node(1);
        root->left = node(2);
        root->right = node(3);
        root->left->right = node(4);
        root->right->left = node(5);
        root->right->right = node(6);
        root->left->right->right = node(7);
        return expectEq(Solution().diagonal(root), vector<int>{1, 3, 6, 2, 4, 7, 5});
    });

    T.test("duplicate values are kept", [] {
        Node* root = node(5);
        root->left = node(5);
        root->right = node(5);
        root->left->left = node(5);
        return expectEq(Solution().diagonal(root), vector<int>{5, 5, 5, 5});
    });

    T.test("deep alternating path", [] {
        Node* root = node(1);
        root->left = node(2);
        root->left->right = node(3);
        root->left->right->left = node(4);
        root->left->right->left->right = node(5);
        return expectEq(Solution().diagonal(root), vector<int>{1, 2, 3, 4, 5});
    });

    T.test("large right chain timing check", [] {
        Node* root = node(0);
        Node* current = root;
        for (int value = 1; value < 100000; value++) {
            current->right = node(value);
            current = current->right;
        }
        vector<int> got = Solution().diagonal(root);
        return expectEq(got.size(), (size_t)100000);
    });

    return T.summary();
}
