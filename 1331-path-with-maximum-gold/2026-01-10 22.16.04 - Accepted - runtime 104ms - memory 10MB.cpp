class Solution {
public:
    int ans=0;
    vector<pair<int,int>> dirs = {{-1, 0},{1, 0},{0,-1},{0, 1}};
    void solve(int i,int j,vector<vector<int>>& grid,int cnt){
        int m=grid.size();
        int n=grid[0].size();
        ans=max(ans,cnt);
        for(auto [dx,dy]:dirs){
            int row=i+dx;
            int col=j+dy;
            if(row>=0 && col>=0 && row<m && col<n && grid[row][col]!=0){
                int gold = grid[row][col];
                grid[row][col] = 0;         
                solve(row,col,grid,cnt+gold); 
                grid[row][col] = gold;     
            }
             
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    int gold=grid[i][j];
                    grid[i][j]=0;
                    solve(i,j,grid,gold);
                    grid[i][j]=gold;
                }
            }
        }
        return ans;
    }
};