class Solution {
public:
    bool checkpal(string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void generate(int idx,string& s,vector<string>& v,vector<vector<string>>& ans){
        if(idx==s.length()){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(checkpal(s,idx,i)==true){
                v.push_back(s.substr(idx,i-idx+1));
                generate(i+1,s,v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        generate(0,s,v,ans);
        return ans;
    }
};