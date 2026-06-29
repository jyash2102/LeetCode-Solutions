class Solution {
public:
    int recur(vector<int>& nums, int target,int idx){
    int n = nums.size();
    if(target==0 && n==idx) return 1;
    if(idx>=n) return 0;
    int add=recur(nums,target-nums[idx],idx+1);
    int sub=recur(nums,target+nums[idx],idx+1);
    return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recur(nums,target,0);
    }
};