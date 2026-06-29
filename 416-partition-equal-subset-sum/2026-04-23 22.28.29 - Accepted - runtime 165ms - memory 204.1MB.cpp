class Solution {
public:
    bool recur(int idx,vector<int>& nums,int sum,vector<vector<int>>& dp){
        int n = nums.size();
        if(sum==0) return true;
        if(idx==0) return(nums[0]==sum);
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool nottake=recur(idx-1,nums,sum,dp);
        bool take = false;
        if(nums[idx]<=sum) take=recur(idx-1,nums,sum-nums[idx],dp);
        return dp[idx][sum] = take | nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return recur(n-1,nums,sum/2,dp);
    }
};