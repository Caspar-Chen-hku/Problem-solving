class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int x = 0, temp;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]!=0){
                temp = nums[x];
                nums[x] = nums[i];
                nums[i] = temp;
                x++;
            }
        }
    }
};