class Solution {
public:
    void generate(vector<vector<int>>& ans,vector<int>& nums,vector<int>& v,vector<int>& visited){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]!=1){
                v.push_back(nums[i]);
                visited[i]++;
                generate(ans,nums,v,visited);
                v.pop_back();
                visited[i]--;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> visited(nums.size(),0);
        generate(ans,nums,v,visited);
        return ans;
    }
};