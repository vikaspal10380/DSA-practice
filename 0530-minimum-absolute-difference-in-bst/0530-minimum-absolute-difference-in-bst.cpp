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
    void inorder(TreeNode* root, int& prev, int& ans, bool& first){
        if(!root){
            return;
        }

        inorder(root->left, prev, ans, first);

        if(first == false){
            ans = min(ans, root->val - prev);
        }
        prev = root->val;
        first = false;

        inorder(root->right, prev, ans, first);
    }
    int getMinimumDifference(TreeNode* root) {
        int prev = 0;
        int ans = INT_MAX;
        bool first = true;
        inorder(root, prev, ans, first);
        return ans;
    }
};