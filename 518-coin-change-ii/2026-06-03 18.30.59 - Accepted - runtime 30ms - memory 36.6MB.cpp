class Solution {
public:
    int  recur(int idx,int amount, vector<int>& coins,vector<vector<int>>& dp){
        if(idx==0){
            if(amount == 0 || amount%coins[idx]==0) return 1;
            return 0;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int nottake=recur(idx-1,amount,coins,dp);
        int take=0;
        if(amount>=coins[idx]) take=recur(idx,amount-coins[idx],coins,dp);
        return dp[idx][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return recur(n-1,amount,coins,dp);
    }
};