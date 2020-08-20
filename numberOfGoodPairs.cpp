class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> occur;
        for (int n:nums){
            occur[n]++;
        }
        int res = 0;
        for (auto m:occur){
            res += m.second * (m.second-1) / 2;
        }
        return res;
    }
};