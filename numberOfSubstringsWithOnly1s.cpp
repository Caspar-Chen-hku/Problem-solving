class Solution {
public:
    int numSub(string s) {
        long res = 0, cur = 0;
        int mod = 1e9+7;
        for (char c:s){
            if (c=='0'){
                res += cur*(cur+1)/2;
                res %= mod;
                cur = 0;
            }else{
                cur++;
            }
        }
        return (res + cur*(cur+1)/2) % mod;
    }
};