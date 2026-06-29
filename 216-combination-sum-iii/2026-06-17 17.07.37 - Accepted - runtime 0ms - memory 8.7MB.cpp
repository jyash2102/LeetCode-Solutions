class Solution {
public:
    void generate(vector<vector<int>>& ans,vector<int>& v,int k,int target,int idx){
        if(target==0 && k==0){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<=9;i++){
            if(target<i) break;
            v.push_back(i);
            generate(ans,v,k-1,target-i,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        generate(ans,v,k,n,1);
        return ans;
    }
};