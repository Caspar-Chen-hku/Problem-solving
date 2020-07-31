class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int res = 0, cur;
        while (i<j){
            cur = min(height[i], height[j]);
            res = max(res, (j-i)*cur);
            if (height[i]==cur){
                i++;
            }else{
                j--;
            }
        }
        return res;
    }
};