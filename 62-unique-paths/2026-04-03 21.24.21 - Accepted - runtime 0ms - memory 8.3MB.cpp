class Solution {
public:
    int recur(int m, int n,int row,int col,vector<vector<int>>& dp){
        if(row<0 || col<0 || row>=m ||  col>=n) return 0;
        if(row==0 && col==0) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int up=recur(m,n,row-1,col,dp);
        int left=recur(m,n,row,col-1,dp);
        return dp[row][col]=up+left;
    }
    int tab(int m,int n){
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        for(int i=0;i<m;i++) dp[i][0]=1;
        for(int j=0;j<n;j++) dp[0][j]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int up=dp[i-1][j];
                int left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return  dp[m-1][n-1];
    }
    int spacetab(int m,int n){
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j]=1;
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0) up=prev[j];
                if(j>0) left=temp[j-1];
                temp[j]=up+left;
            }
            prev=temp;
        }
        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
        return spacetab(m,n);
    }
};