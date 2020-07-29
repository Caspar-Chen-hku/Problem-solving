int binarySearch(vector<int> nums, int at_least){
	int i=0, j=nums.size()-1, mid;
	while (i <= j){
		mid = (i+j)/2;
		if (nums[mid] >= at_least && (mid==0 || nums[mid-1] < at_least)){
			return mid;
		}else if (nums[mid] < at_least){
			i = mid+1;
		}else{
			j = mid-1;
		}
	}
	return 0;
}