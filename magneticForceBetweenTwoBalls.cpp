class Solution {
    bool can(vector<int> position, int m, int dis){
        int cur = 1, last = position[0];
        for (int i=1; i<position.size(); i++){
            if (position[i] - last >= dis){
                cur++; last = position[i];
                if (cur >= m) return true;
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int i=1, j = position.back() - position[0], mid;
        while (i < j){
            mid = (i+j+1)/2;
            if (can(position, m, mid)){
                i = mid;
            }else{
                j = mid-1;
            }
        }
        return i;
    }
};