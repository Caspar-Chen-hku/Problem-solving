class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        else if (nums.size()==1) return nums[0];
        int res1 = help(vector<int>(++nums.begin(), nums.end()));
        nums.pop_back();
        return max(res1, help(nums));
    }
    
    int help(vector<int> nums){
        vector<int> dp(nums.size()+1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i=2; i<=nums.size(); i++){
            dp[i] = max(dp[i-1], nums[i-1]+dp[i-2]);
        }
        return dp.back();
    }
};