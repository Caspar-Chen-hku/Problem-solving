class Solution {
    void visit(int cur, vector<bool>& visited, vector<vector<int>>& graph, stack<int>& nodes){
        visited[cur] = true;
        for (int n:graph[cur]){
            if (!visited[n]){
                visit(n, visited, graph, nodes);
            }
        }
        nodes.push(cur);
    }
    
    void get(int cur, vector<bool>& visited, vector<vector<int>>& graph){
        visited[cur] = true;
        for (int n:graph[cur]){
            if (!visited[n]){
                get(n, visited, graph);
            }
        }
    }
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        stack<int> nodes;
        vector<vector<int>> graph(n);
        for (auto e:edges){
            graph[e[0]].push_back(e[1]);
        }
        vector<bool> visited(n);
        for (int i=0; i<n; i++){
            if (!visited[i]){
                visit(i, visited, graph, nodes);
            }
        }
        for (int i=0; i<n; i++){
            visited[i] = false;
        }
        vector<int> res;
        while (!nodes.empty()){
            int cur = nodes.top();
            nodes.pop();
            if (!visited[cur]){
                get(cur, visited, graph);
                res.push_back(cur);
            }
        }
        return res;
    }
};