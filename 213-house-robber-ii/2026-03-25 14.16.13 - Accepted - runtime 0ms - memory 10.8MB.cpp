class Solution {
public:
    int recur(vector<int>& nums,int idx,int limit,vector<int>& dp){
        if(idx>limit) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int left=nums[idx]+recur(nums,idx+2,limit,dp);
        int right=recur(nums,idx+1,limit,dp);
        return dp[idx]=max(left,right);
    }
    int rob(vector<int>& nums){
        if (nums.size() == 1) return nums[0]; 
        int n = nums.size();
        vector<int> dp(nums.size(),-1);
        int left=recur(nums,1,n-1,dp);
        dp.assign(n,-1);
        int right=recur(nums,0,n-2,dp);
        return max(left,right);
    }
};