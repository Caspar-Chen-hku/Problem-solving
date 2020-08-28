class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cur = 0;
        for (int a:arr){
            if (a%2==1){
                cur++;
                if (cur==3) return true;
            }else{
                cur = 0;
            }
        }
        return false;
    }
};