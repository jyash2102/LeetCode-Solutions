class Solution {
public:
    string reverseByType(string s) {
        int n = s.length();
        vector<char> charr;
        vector<char> special;
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z') charr.push_back(s[i]);
            else special.push_back(s[i]);
        }
        int i=charr.size()-1;
        int j=special.size()-1;
        string ans;
        for(int k=0;k<n;k++){
            if(s[k]>='a' && s[k]<='z'){
                ans.push_back(charr[i]);
                i--;
            }
            else{
                ans.push_back(special[j]);
                j--;
            }
        }
        return ans;
    }
};