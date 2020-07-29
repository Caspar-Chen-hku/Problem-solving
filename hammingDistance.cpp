int hammingDistance(vector<int> nums){
	int res = 0, count0, count1;
	for (int i=0; i<32; i++){
		count0 = 0, count1 = 0;
		for (int n:nums){
			if ((n & 1<<i) == 0){
				count0++;
			}else{
				count1++;
			}
		}
		res += count1*count0;
	}
	return res;
}