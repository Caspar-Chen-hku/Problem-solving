class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int res = 0;
        for (int i=0, j=piles.size()-2; i<j; i++, j-=2){
            res += piles[j];
        }
        return res;
    }
};