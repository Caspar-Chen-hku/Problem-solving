int binarySubarraySum(vector<int> nums, int s){
	int i=0, j=0, res=0, cur=0;
	while (j < nums.size()){
		while (j < nums.size() && cur+nums[j]<=s){
			cur += nums[j++];
			if (cur==s) res++; 
		}
		while (i < j && cur>=s){
			cur -= nums[i++];
			if (cur >= s) res++;
		}
	}
	return res;
}

int binarySubarraySum1(vector<int> nums, int s){
	map<int,int> m;
	vector<int> presum(nums.size()+1);
	for (int i=1; i<=nums.size(); i++){
		presum[i] = presum[i-1] + nums[i-1];
	}
	int res = 0;
	for (int i=1; i<=nums.size(); i++){
		m[presum[i-1]]++;
		res += m[presum[j]-s];
	}
	return res;
}