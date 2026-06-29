class Solution {
public:
    void recur(vector<vector<int>>& ans,vector<int>& v,int target,vector<int>& nums,int idx){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(target>=nums[i]){
                v.push_back(nums[i]);
                recur(ans,v,target-nums[i],nums,i);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        recur(ans,v,target,candidates,0);
        return ans;
    }
};