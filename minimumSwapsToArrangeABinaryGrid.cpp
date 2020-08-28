class Solution {
public:
	int minSwaps(vector<vector<int>>& A) {
		const int N=A.size();
		vector<vector<int>> G(N);
		// O(N^2)
		for(int i=0; i<N; i++) {
			int x=N;
			while(--x && !A[i][x]);
			G[N-x-1].push_back(i);
		}
		// O(NlgN)
		int sum=0;
		vector<int> T(N+1);
		priority_queue<int> Q;
		for(int i=0; i<N; i++) {
			for(int j:G[N-i-1]) Q.push(-j);
			if(Q.empty()) return -1;
			int j=-Q.top();
			Q.pop();
			sum+=j-i;
			for(int k=N-j; k; k-=k&-k) sum+=T[k];
			for(int k=N-j; k<=N; k+=k&-k) T[k]++;
		}
		return sum;
	}
};