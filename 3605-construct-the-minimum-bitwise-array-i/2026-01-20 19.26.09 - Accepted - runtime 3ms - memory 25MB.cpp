class Solution {
public:
    int mini(int k){
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            int OR= i | (i+1);
            if(OR==k){
                ans=i;
                break;
            }
        }
        if(ans==INT_MAX) return-1;
        return ans;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=mini(nums[i]);
        }
        return ans;
    }
};