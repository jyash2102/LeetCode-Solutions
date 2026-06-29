class Solution {
public:
    void generate(vector<vector<int>>& ans,vector<int>& v,int idx,vector<int>&nums,int target){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>target) break;
            v.push_back(nums[i]);
            generate(ans,v,i+1,nums,target-nums[i]);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        generate(ans,v,0,candidates,target);
        return ans;
    }
};