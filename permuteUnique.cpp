class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return get(nums, nums.size()-1);
    }
    
    vector<vector<int>> get(vector<int>& nums, int ind){
        if (ind == 0){
            return {{nums[0]}};
        }
        vector<vector<int>> res;
        set<int> prev;
        for (int i=0; i<=ind; i++){
            if (prev.find(nums[i])!=prev.end()){
                continue;
            }else{
                prev.insert(nums[i]);
            }
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