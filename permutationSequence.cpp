class Solution {
public:
    
    int get(set<int> nums, int k){
        for (int i:nums){
            if (k==0) return i;
            else k--;
        }
        return 0;
    }
    
    string getPermutation(int n, int k) {
        string res;
        int divide = 1;
        set<int> nums;
        for (int i=1; i<n; i++){
            divide *= i;
            nums.insert(i);
        }
        nums.insert(n);
        k--;
        while (nums.size()>1){
            int cur = k/divide;
            int temp = get(nums, cur);
            res.push_back(temp+'0');
            k %= divide;
            nums.erase(temp);
            n--;
            divide /= n;
        }
        res.push_back(*nums.begin()+'0');
        return res;
    }
};