class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, right0 = 0, left2 = nums.size()-1, temp;
        while (i<=left2){
            if (nums[i]==0){
                nums[i] = nums[right0];
                nums[right0] = 0;
                right0++; i++;
            }else if (nums[i]==2){
                nums[i] = nums[left2];
                nums[left2] = 2;
                left2--;
            }else{
                i++;
            }
        }
    }
};