class Solution {
public:
    int recur(vector<vector<int>>& grid,int row,int col1,int col2,vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(row<0 || col1<0 || row>=n || col1>=m || col2>=m || col2<0 ) return 0;
        if(row==n){
            return 0;
        }
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
        int maxi=INT_MIN;
        int curr;
        if(col1==col2) curr=grid[row][col1];
        else curr=grid[row][col1]+grid[row][col2];
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int ans=curr+recur(grid,row+1,col1+i,col2+j,dp);
                maxi=max(ans,maxi);
            }
        }
        return dp[row][col1][col2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(m, -1)));
        return recur(grid,0,0,m-1,dp);
    }
};