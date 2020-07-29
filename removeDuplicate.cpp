vector<int> removeDuplicate(vector<int> nums){
	vector<int> res = {nums[0]};
	for (int i=1; i<nums.size(); i++){
		if (nums[i]!=nums[i-1]){
			res.push_back(nums[i]);
		}
	}
	return res;
}