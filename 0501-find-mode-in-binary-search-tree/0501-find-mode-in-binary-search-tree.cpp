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
    void inorder(TreeNode* root, int& prev, int& counter, int& maxCount, vector<int>& ans, bool& first){
        if(!root){
            return;
        }

        inorder(root->left, prev, counter, maxCount, ans, first);
        if(first == true){
            counter = 1;
            prev = root->val;
            first = false;
        }
        else{
            if(root->val == prev){
                counter++;
            }
            else{
                counter = 1;
                prev = root->val;
            }
        }
        if(counter > maxCount){
            maxCount = counter;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(counter == maxCount){
            ans.push_back(root->val);
        }
        inorder(root->right, prev, counter, maxCount, ans, first);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int prev = 0;
        int counter = 0;
        int maxCount = 0;
        bool first = true;

        inorder(root, prev, counter, maxCount, ans, first);
        return ans;
    }
};