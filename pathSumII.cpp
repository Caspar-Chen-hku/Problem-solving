class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) return {};
        path(root, sum, res, {});
        return res;
    }
    
    void path(TreeNode* root, int sum, vector<vector<int>>& res, vector<int> cur){
        if (!root->left && !root->right){
            if (root->val == sum){
                cur.push_back(root->val);
                res.push_back(cur);  
            } 
        }else if (!root->left){
            cur.push_back(root->val);
            path(root->right, sum-root->val, res, cur);
        }else if (!root->right){
            cur.push_back(root->val);
            path(root->left, sum-root->val, res, cur);
        }else{
            cur.push_back(root->val);
            path(root->left, sum-root->val, res, cur);
            path(root->right, sum-root->val, res, cur);
        }
    }
};