// Diagonal Traversal of Binary Tree  [GFG]

/* Structure of binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        queue<Node*> q;
        vector<int> ans;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            while(node != nullptr){
                ans.push_back(node->data);
                if(node->left != nullptr)  q.push(node->left);
                node = node->right;
            }
        } 

        return ans;
    }
};

// 8,10,14, 3,6,7,13,1,4
//  1, 4