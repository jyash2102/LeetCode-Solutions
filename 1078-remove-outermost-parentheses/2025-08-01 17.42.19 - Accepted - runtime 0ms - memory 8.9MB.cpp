class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string str;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(cnt!=0) str.push_back(s[i]);
                cnt++;
            }
            else{
                cnt--;
                if(cnt!=0) str.push_back(s[i]);
            }
        }
        return str;
    }
};