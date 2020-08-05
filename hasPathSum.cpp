class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        else if (!root->left && !root->right) return root->val == sum;
        sum -= root->val;
        if (!root->left) return hasPathSum(root->right, sum);
        else if (!root->right) return hasPathSum(root->left, sum);
        else return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};