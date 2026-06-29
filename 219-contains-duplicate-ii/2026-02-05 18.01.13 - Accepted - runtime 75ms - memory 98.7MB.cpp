class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int i=0,j=0;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp[nums[j]]==2){
                if(j-i<=k){
                    return true;
                }
                mpp[nums[i]]--;
                i++;
            }
            j++;
        }
        return false;
    }
};