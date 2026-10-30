// 272. Closest Binary Search Tree Value II  [Hard]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> arr;
    vector<int> ans;

    void inorder(TreeNode *root){
        if(root == nullptr) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        inorder(root);
        auto itr = lower_bound(arr.begin(), arr.end(), target);
        int left = 0, right = 0;
        if(itr == arr.end()){
            left = arr.size()-1;
            right = arr.size()-1;
        }
        else{
            right = itr - arr.begin();
            left = right-1;
        }

        while(k){
            if(right >= arr.size()){
                ans.push_back(arr[left]);
                left--;
            }
            else if(left < 0){
                ans.push_back(arr[right]);
                right++;
            }
            else if(left == right){
                ans.push_back(arr[right]);
                left--;
                right++;
            }
            else{
                if(abs(target - arr[left]) <= abs(target - arr[right])){
                    ans.push_back(arr[left]);
                    left--;
                }
                else{
                    ans.push_back(arr[right]);
                    right++;
                }
            }
            k--;
        }

        return ans;
    }
};
