class Solution {
public:
    int dfs(int ans,int node,vector<vector<pair<int,int>>>& adj,vector<bool>& vis){
        vis[node]=true;
        for(auto& [n,w] : adj[node]){
            ans=min(w,ans);
            if(!vis[n]) ans=min(ans,dfs(ans,n,adj,vis));
        }
        return ans;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<bool> vis(n+1,false);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int c=roads[i][2];
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        return dfs(INT_MAX,1,adj,vis);
    }
};