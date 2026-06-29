class Solution {
public:
    int recur(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(row<0 || col<0 || row>=n || col>=m) return 1000000;
        if(row==0 && col==0) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int up=grid[row][col]+recur(grid,row-1,col,dp);
        int left=grid[row][col]+recur(grid,row,col-1,dp);
        return dp[row][col]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recur(grid,n-1,m-1,dp);
    }
};