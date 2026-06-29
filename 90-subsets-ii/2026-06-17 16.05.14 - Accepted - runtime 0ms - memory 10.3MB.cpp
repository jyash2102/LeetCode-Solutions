class Solution {
public:
    void generate(vector<vector<int>>& ans,vector<int>& v,vector<int>& nums,int idx){
        ans.push_back(v);
        if(idx>=nums.size()) return;
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            generate(ans,v,nums,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        generate(ans,v,nums,0);
        return ans;
    }
};