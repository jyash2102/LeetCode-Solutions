class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mpp;
        for (int i=0;i<n;i++) {
            mpp[nums[i]]++;
            if(mpp[nums[i]]==2) ans.push_back(nums[i]);
        }
        
        return ans;
    }
};