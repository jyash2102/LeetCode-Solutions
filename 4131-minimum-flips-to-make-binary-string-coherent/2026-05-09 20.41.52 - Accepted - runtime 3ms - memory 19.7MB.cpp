class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int ones=0;
        for(char ch:s){
            if(ch=='1') ones++;
        }
        int ans=min({ones,n-ones,(ones>0) ? ones-1 : 1});
        if(n>=2){
            int c=(s[0]=='0') + (s.back()=='0') + ones - (s[0]=='1') - (s.back()=='1');
            ans=min(ans,c);
        }
        return ans;
        
    }
};