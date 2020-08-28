class Solution {
    int getmax(vector<int> arr){
        int res = INT_MIN;
        for (int a:arr){
            res = max(res, a);
        }
        return res;
    }
public:
    int getWinner(vector<int>& arr, int k) {
        if (k >= arr.size()) return getmax(arr);
        int cur = 0;
        for (int i=0; i<arr.size(); i++){
            if (arr[i] > arr[i+1]){
                cur++;
                if (cur >= k) return arr[i];
                arr.push_back(arr[i+1]);
                arr[i+1] = arr[i];
            }else{
                cur = 1;
                if (cur >= k) return arr[i+1];
                arr.push_back(arr[i]);
            }
        }
        return 0;
    }
};