class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numbers;
        int cur = 1, res = 0;
        if (!nums.empty()) res = 1;
        for (int n:nums){
            numbers.insert(n);
        }
        int last = INT_MIN;
        for (int n:numbers){
            if (n==last+1){
                cur++; 
                res = max(res, cur);
            }else{
                cur = 1;
            }
            last = n;
        }
        return res;
    }
};