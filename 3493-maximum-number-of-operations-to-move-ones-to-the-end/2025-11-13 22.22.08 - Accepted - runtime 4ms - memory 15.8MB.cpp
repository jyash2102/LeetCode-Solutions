class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int cnt=0;
        int cnt1=0;
        int i=0;
        while(i<n){
            while(s[i]=='0' && i<n){
                i++;
            }
            while(s[i]=='1' && i<n){
                cnt1++;
                i++;
            }
            if(s[i]=='0') cnt+=cnt1;
        }
        return cnt;
    }
};