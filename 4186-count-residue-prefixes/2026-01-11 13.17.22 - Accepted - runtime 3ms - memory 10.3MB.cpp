class Solution {
public:
    int residuePrefixes(string s) {
        unordered_map<int,int> mpp;
        int n = s.length();
        int c=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mpp[s[i]]==0){
                c++;
                mpp[s[i]]++;
            }
            if(c==(i+1)%3) cnt++;
        }
        return cnt;
    }
};