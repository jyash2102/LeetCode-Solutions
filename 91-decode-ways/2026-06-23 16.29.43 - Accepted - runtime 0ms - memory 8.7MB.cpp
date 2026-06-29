class Solution {
public:
    bool isvalid(string &s){
        if(s.length()>2) return false;
        int num=0;
        for(int i=0;i<s.length();i++){
            int n = s[i]-'0';
            num*=10;
            num+=n;
        }
        return (num>=1 && num<=26);
    }
    int decode(int idx,string s,vector<int>& dp){
        if(idx==s.length()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        int ans=0;
        for(int l=1;l<=2 && idx+l<=s.length();l++){
            string temp=s.substr(idx,l);
            if(temp[0]=='0') break;
            if(isvalid(temp)) ans+=decode(idx+l,s,dp);
        }
        return dp[idx]=ans;
    }
    int tab(string s,vector<int>& dp){
        dp[s.length()]=1;
        for(int i=s.length()-1;i>=0;i--){
            int ans=0;
            for(int l=1;l<=2 && i+l<=s.length();l++){
                string temp=s.substr(i,l);
                if(temp[0]=='0') break;
                if(isvalid(temp)) ans+=dp[i+l];
            }
            dp[i]=ans;
        }
        return dp[0];
    }
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
        return tab(s,dp);
    }
};