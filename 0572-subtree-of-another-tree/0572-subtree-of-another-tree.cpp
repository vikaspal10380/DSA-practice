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
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot){
            return true;
        }
        if(!root || !subRoot){
            return false;
        }
        if(root->val != subRoot->val){
            return false;
        }

        bool left = isSame(root->left, subRoot->left);
        bool right = isSame(root->right, subRoot->right);

        if(left && right){
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return false;
        }
        if(isSame(root, subRoot)){
            return true;
        }
        bool left = isSubtree(root->left, subRoot);

        if(left){
            return true;
        }
        bool right = isSubtree(root->right, subRoot);

        if(right){
            return true;
        }
        return false;
    }
};