class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.length();
        int XOR1=0;
        for(int i=0;i<n;i++){
            XOR1^=s[i];
        }
        int XOR2=0;
        for(int i=0;i<n+1;i++){
            XOR2^=t[i];
        }
        return char(XOR1^XOR2);
    }
};