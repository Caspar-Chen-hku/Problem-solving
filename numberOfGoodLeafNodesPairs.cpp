class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        vector<int> leaves; int res = 0;
        visit(root, distance, 0, leaves, res);
        return res;
    }
    
    void visit(TreeNode* root, int distance, int depth, vector<int>& leaves, int& res){
        if (!root->left && !root->right){
            if (depth <= distance)
                leaves.push_back(depth);
        }else if (!root->left){
            visit(root->right, distance, depth+1, leaves, res);
        }else if (!root->right){
            visit(root->left, distance, depth+1, leaves, res);
        }else{
            vector<int> l, r;
            visit(root->left, distance, 1, l, res);
            visit(root->right, distance, 1, r, res);
            for (int lnode:l){
                for (int rnode:r){
                    if (lnode+rnode <= distance) res++;
                }
            }
            for (int lnode:l){
                if (lnode+depth <= distance) leaves.push_back(lnode+depth);
            }
            for (int rnode:r){
                if (rnode+depth <= distance) leaves.push_back(rnode+depth);
            }
        }
    }
};