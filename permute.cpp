class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return get(nums, nums.size()-1);
    }
    
    vector<vector<int>> get(vector<int>& nums, int ind){
        if (ind == 0){
            return {{nums[0]}};
        }
        vector<vector<int>> res;
        for (int i=0; i<=ind; i++){
            swap(nums[i], nums[ind]);
            vector<vector<int>> cur = get(nums, ind-1);
            for (auto p:cur){
                p.push_back(nums[ind]);
                res.push_back(p);
            }
            swap(nums[i], nums[ind]);
        }
        return res;
    }
};