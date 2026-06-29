class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        if(s[0]=='1' && n==1) return true;
        int idx=-1;
        if(s[0]=='1') idx=0;
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                if(s[i-1]=='1' && idx==i-1){
                    idx=i;
                    continue;
                }
                else return false;
            }
        }
        return true;
    }
};