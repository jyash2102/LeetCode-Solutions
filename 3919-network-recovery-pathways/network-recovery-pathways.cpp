class Solution {
#define ll long long
public:
    const ll INF=1e18;
    long long recur(int node,int mid,vector<ll>& cost,vector<vector<pair<int,ll>>>& adj,vector<bool>& online){
        int n = online.size();
        if(node==n-1) return 0;
        if(cost[node]!=-1) return cost[node];
        ll ans=INF;
        for(auto& [nxt,wt] : adj[node]){
            if(wt<mid) continue;
            if(nxt!=n-1 && !online[nxt]) continue;
            ll child=recur(nxt,mid,cost,adj,online);
            if(child != INF) {
                ans = min(ans, wt + child);
            }
        }
        return cost[node]=ans;
    }
    bool check(int mid,vector<vector<pair<int,ll>>>& adj,vector<bool>& online,ll k){
        int n = online.size();
        vector<ll> cost(n,-1);
        long long minCost = recur(0, mid, cost, adj, online);
        return minCost <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,ll>>> adj(n);
        int high=0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int c=edges[i][2];
            adj[u].push_back({v,c});
            high=max(c,high);
        }
        int low=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,adj,online,k)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};