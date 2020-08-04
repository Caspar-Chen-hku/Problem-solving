class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i = 0, j= n-1, temp;
        while (i<j){
            for (int x=0; x<j-i; x++){
                temp = matrix[i][i+x];
                matrix[i][i+x] = matrix[j-x][i];
                matrix[j-x][i] = matrix[j][j-x];
                matrix[j][j-x] = matrix[i+x][j];
                matrix[i+x][j] = temp;
            }
            i++; j--;
        }
    }
};