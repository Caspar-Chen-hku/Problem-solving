class Solution {
    int res = INT_MIN;
    public:
    
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return res;
    }
    
    int maxPath(TreeNode* root){
        if (!root) return 0;
        int cur = root->val;
        int l = maxPath(root->left);
        int r = maxPath(root->right);
        cur += max(max(l, r), 0);
        res = max(max(res, cur), l+root->val+r);
        return cur;
    }
};