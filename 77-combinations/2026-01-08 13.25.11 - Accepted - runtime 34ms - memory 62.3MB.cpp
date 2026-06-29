class Solution {
public:
    void generate(int idx,vector<vector<int>>& ans,vector<int>& v,int n,int k){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<=n;i++){
            v.push_back(i);
            generate(i+1,ans,v,n,k);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        generate(1,ans,v,n,k);
        return ans;
    }
};