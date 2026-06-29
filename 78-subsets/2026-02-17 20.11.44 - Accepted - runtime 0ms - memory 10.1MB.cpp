class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int subset=(1<<n);
        for(int i=0;i<subset;i++){
            vector<int> s;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    s.push_back(nums[j]);
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};