class Solution {
    void dfs(int x, int parent, string &s, vector<vector<int>>& graph, vector<vector<int>>& dp){
        for(int i=0; i<graph[x].size(); i++){
            if(graph[x][i]!=parent)
                dfs(graph[x][i],x,s,graph,dp);
        }
        dp[x][s[x]-'a']++;
        for(int i=0;i<graph[x].size();i++){
            if(graph[x][i]==parent)
                continue;
            for(int j=0;j<26;j++)
                dp[x][j]+=dp[graph[x][i]][j];
        }
    }
    
    public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edg, string s) {
        vector<int> ans(n);
        vector<vector<int>> graph(n);
        vector<vector<int>> dp(n, vector<int>(26));
        int i,j;
        for(i=0;i<n-1;i++){
            graph[edg[i][0]].push_back(edg[i][1]);
            graph[edg[i][1]].push_back(edg[i][0]);
        }
        dfs(0, -1, s, graph, dp);
        for(i=0; i<n; i++)
            ans[i] = dp[i][s[i]-'a'];
        return ans;
    }
};