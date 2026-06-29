class Solution {
public:
    int recur(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>& dp){
        int n = matrix.size();
        if(row<0 || col<0 || row>=n || col>=n) return 1e9;
        if(row==0) return matrix[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int up=matrix[row][col]+recur(matrix,row-1,col,dp);
        int dleft=matrix[row][col]+recur(matrix,row-1,col-1,dp);
        int dright=matrix[row][col]+recur(matrix,row-1,col+1,dp);
        return dp[row][col]=min({up,dleft,dright});
    }
    int spacetab(vector<vector<int>>& matrix){
        int n = matrix.size();
        vector<int> prev(n);
        for(int j=0;j<n;j++) prev[j]=matrix[0][j];
        for(int i=1;i<n;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+prev[j];
                int dleft=1e9;
                int dright=1e9;
                if(j>0) dleft=matrix[i][j]+prev[j-1];
                if(j<n-1) dright=matrix[i][j]+prev[j+1];
                temp[j]=min({up,dleft,dright});
            }
            prev=temp;
        }
        return *min_element(prev.begin(),prev.end());
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int ans=1e9;
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // for(int j=0;j<n;j++){
        //     ans=min(ans,recur(matrix,n-1,j,dp));
        // }
        return spacetab(matrix);
    }
};