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
    int length(TreeNode* root, int& ans){
        if(root == NULL){
            return 0;
        }
        int left = length(root->left, ans);
        int right = length(root->right, ans);

        int diameter = left+right;
        ans = max(diameter,ans);
        if(left > right){
            return left+1;
        }
        else{
            return right+1;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        length(root, ans);
        return ans;
        
    }
};