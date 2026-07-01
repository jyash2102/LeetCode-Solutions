class Solution {
public:
    int maxi=-1e9;
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
    void caldis(vector<vector<int>>& dist,queue<pair<int,int>>& q){
        int n = dist.size();
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(auto [dx,dy] : dir){
                int nr=i+dx;
                int nc=j+dy;
                if(nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc]==1e9){
                    dist[nr][nc] = dist[i][j] + 1;
                    maxi=max(maxi,dist[nr][nc]);
                    q.push({nr,nc});
                }
            }
        }
    }
    bool bfs(int mid,vector<vector<int>>& dist){
        int n = dist.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(dist[0][0]<mid) return false;
        q.push({0,0});
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(auto [dx,dy] : dir){
                int nr=i+dx;
                int nc=j+dy;
                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && dist[nr][nc]>=mid){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return (vis[n-1][n-1]==1);
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        caldis(dist,q);
        int low=0;
        int high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(bfs(mid,dist)) low=mid+1;
            else high=mid-1;
        }
        return(high==-1e9)?0:high;
    }
};