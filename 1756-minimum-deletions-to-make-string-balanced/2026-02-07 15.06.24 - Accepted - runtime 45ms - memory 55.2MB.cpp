class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> preb(n);
        vector<int> posta(n);
        int cntb=0;
        for(int i=0;i<n;i++){
            preb[i]=cntb;
            if(s[i]=='b') cntb++;
        }
        int cnta=0;
        for(int i=n-1;i>=0;i--){
            posta[i]=cnta;
            if(s[i]=='a') cnta++;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,preb[i]+posta[i]);
        }
        return ans;
    }
};