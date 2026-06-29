class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string t;
        for(int i=0;i<n;i++){
            if(s[i]=='*' && !t.empty()) t.pop_back();
            else if(s[i]=='#') t.append(t);
            else if(s[i]=='%') reverse(t.begin(),t.end());
            else if(s[i]!='*') t.push_back(s[i]);
        }
        return t;
    }
};