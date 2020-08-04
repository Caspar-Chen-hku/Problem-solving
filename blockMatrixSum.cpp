class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> preSum(m+1, vector<int>(n+1, 0));
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int r1 = max(i-K+1, 1);
                int r2 = min(i+K+1, m);
                int c1 = max(j-K+1, 1);
                int c2 = min(j+K+1, n);
                res[i][j] = preSum[r2][c2] - preSum[r2][c1-1] - preSum[r1-1][c2] + preSum[r1-1][c1-1];
            }
        }
        return res;
    }
};