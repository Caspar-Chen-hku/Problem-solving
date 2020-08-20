class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> res;
        int mod = 1e9+7;
        for (int i=0; i<nums.size(); i++){
            int cur = 0;
            for (int j=i; j<nums.size(); j++){
                cur += nums[j];
                res.push_back(cur);
            }
        }
        partial_sort(res.begin(), res.begin()+right, res.end());
        int sol = 0;
        for (int i=left-1; i<right; i++){
            sol += res[i];
            sol %= mod;
        }
        return sol;
    }
};