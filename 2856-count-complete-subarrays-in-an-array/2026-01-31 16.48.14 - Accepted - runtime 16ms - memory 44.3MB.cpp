class Solution {
public:
    int subarray(vector<int>& nums, int k){
        if(k<0) return 0;
        int n = nums.size();
        unordered_map<int,int> mpp;
        int cnt=0;
        int i=0,j=0;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size()>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            } 
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        return subarray(nums,mpp.size())-subarray(nums,mpp.size()-1);
    }
};