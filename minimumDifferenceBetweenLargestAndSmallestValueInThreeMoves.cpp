class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size()<=4) return 0;
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for (int i=0, j=nums.size()-4; j<nums.size(); i++, j++){
            diff = min(diff, nums[j]-nums[i]);
        }
        return diff;
    }
};