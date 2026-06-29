class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        int n = nums.size();
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int left=dp[i+1];
            int right;
            if(i+2<=n){
                right=dp[i+2]+nums[i];
            }
            else right=nums[i];
            dp[i]=max(left,right);
        }
        return dp[0];
    }
};