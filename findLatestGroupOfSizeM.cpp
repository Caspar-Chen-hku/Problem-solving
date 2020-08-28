class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        vector<int> len(arr.size()+2);
        vector<int> count(arr.size()+1);
        int res = -1, step = 0;
        int left, right;
        for (int i:arr){
            step++;
            left = len[i-1], right = len[i+1];
            len[i-left] = len[i] = len[i+right] = left+right+1;
            count[left]--; count[right]--;
            count[len[i]]++;
            if (count[m]>0) res = step;
        }
        return res;
    }
};