class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9+7;
        vector<int> presum(n+1);
        for (int i=1; i<=n; i++){
            presum[i] = presum[i-1] + arr[i-1];
            presum[i] %= 2;
        }
        vector<int> numZero(n+1);
        for (int i=1; i<=n; i++){
            numZero[i] = numZero[i-1];
            if (presum[i]==0){
                numZero[i]++;
            }
        }
        int res = 0;
        for (int i=1; i<=n; i++){
            if (presum[i]==0){
                res += i-numZero[i];
            }else{
                res += numZero[i]+1;
            }
            res %= mod;
        }
        return res;
    }
};