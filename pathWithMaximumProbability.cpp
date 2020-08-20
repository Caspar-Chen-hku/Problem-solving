class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, 
                          vector<double>& succProb, int s, int e) {
        vector<pair<int,double>> G[n];
        int E=edges.size();
        
        for(int i=0;i<E;i++){
            int u=edges[i][0],v=edges[i][1];
            double w=succProb[i];
            G[u].push_back({v,w});
            G[v].push_back({u,w});
        }
        
        vector<double> pr(n,0.0);
        pr[s]=1.0;
        queue<int> q;
        q.push(s);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(pair<int,double> p:G[node]){
                int x=p.first;
                double w=p.second;
                if(pr[node]*w>pr[x]){
                    q.push(x);
                    pr[x]=pr[node]*w;
                }
            }
        }
        return pr[e];
    }
};