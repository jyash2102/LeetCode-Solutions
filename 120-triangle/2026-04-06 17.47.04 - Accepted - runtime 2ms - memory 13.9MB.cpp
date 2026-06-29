class Solution {
public:
    int recur(vector<vector<int>>& triangle,int row,int col,vector<vector<int>>& dp){
        int n = triangle.size();
        int m = triangle[0].size();
        if(dp[row][col]!=-1) return dp[row][col];
        if(row==n-1) return dp[row][col] = triangle[row][col]; 
        int same=triangle[row][col]+recur(triangle,row+1,col,dp);
        int diag=triangle[row][col]+recur(triangle,row+1,col+1,dp);
        return dp[row][col]=min(same,diag);
    }
    int tab(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }
    int space(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<int> prev(n);
        for(int i=0;i<n;i++) prev[i]=triangle[n-1][i];
        for (int i = n - 2; i >= 0; i--) {
            vector<int> temp(n);
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + prev[j];
                int diag = triangle[i][j] + prev[j + 1];
                temp[j] = min(down, diag);
            }
            prev=temp;
        }
        return prev[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return space(triangle);
    }
};