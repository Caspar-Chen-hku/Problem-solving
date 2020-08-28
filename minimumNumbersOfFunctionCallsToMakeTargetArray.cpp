class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, maxlen = 0, cur;
        for (int i:nums){
            cur = 0;
            while (i > 0){
                cur++;
                res += i%2;
                i /= 2;
            }
            maxlen = max(maxlen, cur);
        }
        return res + maxlen - 1;
    }
};