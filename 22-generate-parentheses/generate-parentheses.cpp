class Solution {
public:
    vector<string> ans;
    void recur(string s,int open,int close,int n){
        if (s.length() == 2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            recur(s+'(',open+1,close,n);
        }
        if(close<open){
            recur(s+')',open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        recur("",0,0,n);
        return ans;
    }
};