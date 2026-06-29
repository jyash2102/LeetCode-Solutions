class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        vector<int> postg(n);
        postg[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            postg[i]=max(postg[i+1],nums[i]);
        }
        int maxi=nums[0];
        for(int i=1;i<n-1;i++){
            if(nums[i]>maxi || nums[i]>postg[i+1]) ans.push_back(nums[i]);
            maxi=max(nums[i],maxi);
        }
        if(n!=1) ans.push_back(nums[n-1]);
        return ans;
    }
};