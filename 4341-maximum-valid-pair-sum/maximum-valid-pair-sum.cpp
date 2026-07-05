class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi=nums[0];
        int ans=0;
        for(int i=k;i<n;i++){
            maxi=max(nums[i-k],maxi);
            int num=maxi+nums[i];
            ans=max(ans,num);
        }
        ans=max(ans,maxi+nums[n-1]);
        return ans;
    }
};