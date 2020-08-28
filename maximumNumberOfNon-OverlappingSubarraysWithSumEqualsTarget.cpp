class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        set<int> s;
        s.insert(0);
        int su = 0, ans = 0;
        for(int i: nums){
            su += i;
            if(s.find(su - target) != s.end()) {
                ans++;
                s.clear();
            }
            s.insert(su);
        }
        return ans;
    }
};