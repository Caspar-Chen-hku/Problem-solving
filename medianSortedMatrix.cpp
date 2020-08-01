int binary_search(vector<int> nums, int target){
	int i=0, j=nums.size()-1, mid;
	while (i<=j){
		mid = (i+j)/2;
		if (nums[mid]<=target && (mid==nums.size()-1 || nums[mid+1]>target)) return mid;
		else if (nums[mid]>target) j=mid-1;
		else i=mid+1;
	}
	return i;
}

int medianSortedMatrix(vector<vector<int>> mat){
	int m = mat.size(), n = mat[0].size();
	int i = INT_MAX, j = INT_MIN;
	for (auto p:mat){
		i = min(p[0], i);
		j = max(p.back(), j);
	}
	int mid, cur, target=m*n/2+1;
	while (i<j){
		mid = (i+j)/2;
		cur = 0;
		for (auto p:mat){
			cur += binary_search(p, mid)+1;
		}
		if (cur>=target){
			j = mid;
		}else{
			i = mid+1;
		}
	}
	return i;
}