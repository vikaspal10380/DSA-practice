class Solution {
public:

    int dfs(TreeNode* root, int current) {

        if (root == NULL) {
            return 0;
        }

        current = current * 10 + root->val;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            return current;
        }

        int left = dfs(root->left, current);
        int right = dfs(root->right, current);

        return left + right;
    }

    int sumNumbers(TreeNode* root) {

        return dfs(root, 0);
    }
};