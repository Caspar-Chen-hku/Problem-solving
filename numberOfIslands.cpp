class Solution {
public:
    
    void visit(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        if (i > 0 && grid[i-1][j]=='1') visit(grid, i-1, j);
        if (i < grid.size()-1 && grid[i+1][j]=='1') visit(grid, i+1, j);
        if (j > 0 && grid[i][j-1]=='1') visit(grid, i, j-1);
        if (j < grid[i].size()-1 && grid[i][j+1]=='1') visit(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j]=='1'){
                    num++;
                    visit(grid, i, j);
                }
            }
        }
        return num;
    }
};