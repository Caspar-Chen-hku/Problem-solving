class Solution {
public:
    
    void visit(vector<vector<int>> graph, vector<bool>& visited, int i){
        visited[i] = true;
        for (int n:graph[i]){
            if (!visited[n]){
                visit(graph, visited, n);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int num = 0, n = M.size();
        vector<vector<int>> graph(n);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (M[i][j]==1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n);
        for (int i=0; i<n; i++){
            if (!visited[i]){
                visit(graph, visited, i);
                num++;
            }
        }
        return num;
    }
};