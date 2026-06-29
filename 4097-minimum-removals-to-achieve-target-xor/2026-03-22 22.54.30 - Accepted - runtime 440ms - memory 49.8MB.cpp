class Solution {
public:
    int dp[41][100000];
    int  recur(vector<int>& nums, int target,int XOR,int idx){
        if(idx>=nums.size()){
            if(XOR==target) return 0;
            return 1e9;
        }
        if(dp[idx][XOR]!=-1) return dp[idx][XOR];
        int left=recur(nums,target,XOR^nums[idx],idx+1);
        int right=1+recur(nums,target,XOR,idx+1);
        return dp[idx][XOR]=min(left,right);
    }
    int minRemovals(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int res = recur(nums, target, 0, 0);
        return (res >= 1e9 ? -1 : res);
    }
};