class Solution {
public:
    vector<int> dp; 
    bool present(int idx, vector<string>& v,string& s){
        if(idx==s.length()) return true;
        if(dp[idx]!=-1) return dp[idx];
        if(find(v.begin(),v.end(),s)!=v.end()) return true;
        for(int l=1;l<=s.length();l++){
            string temp=s.substr(idx,l);
            if(find(v.begin(),v.end(),temp)!=v.end() && present(idx+l,v,s)) return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.length() + 1, -1);
        return present(0,wordDict,s);
    }
};