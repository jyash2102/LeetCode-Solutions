class Solution {
public:
    void recur(int idx,string& s,int n, int k,vector<string>& ans,int cost,int flag){
        if(cost>k) return;
        if(s.length()==n){
            ans.push_back(s);
            return;
        }
        s.push_back('0');
        recur(idx+1,s,n,k,ans,cost,false);
        s.pop_back();
        if(idx==0 || s[idx-1]=='0'){
            s.push_back('1');
            recur(idx+1,s,n,k,ans,cost+idx,true);
            s.pop_back();
        }
        
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        string s="";
        recur(0,s,n,k,ans,0,false);
        return ans;
    }
};