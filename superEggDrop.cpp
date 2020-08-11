class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N+1, vector<int>(K+1, -1));
        return get(K, N, dp);
    }
    
    int get(int eggs, int floor, vector<vector<int>>& dp){
        if (dp[floor][eggs]!=-1) return dp[floor][eggs];
        else if (eggs == 0 || floor == 0) dp[floor][eggs] = 0;
        else if (eggs == 1) dp[floor][eggs] = floor;
        else if (floor == 1) dp[floor][eggs] = 1;
        else{
            int minn = INT_MAX;
            int i = 1, j = floor, mid, a, b;
            while (i <= j){
                mid = (i+j)/2;
                a = get(eggs-1, mid-1, dp);
                b = get(eggs, floor-mid, dp);
                minn = min(minn, max(a, b)+1);
                if (a < b){
                    i = mid+1;
                }else{
                    j = mid-1;
                }
            }
            dp[floor][eggs] = minn;
        }
        return dp[floor][eggs];
    }
};