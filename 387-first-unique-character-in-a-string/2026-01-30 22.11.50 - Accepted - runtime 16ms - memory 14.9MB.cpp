class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<char,pair<int,int>> mpp(26);
        for(int i=0;i<n;i++){
            mpp[s[i]-'a'].first=i;
            mpp[s[i]-'a'].second++;
        }
        int minidx=INT_MAX;
        for(auto it : mpp){
            if(it.second.second==1){
                minidx=min(minidx,it.second.first);
            }
        }
        if(minidx==INT_MAX) return -1;
        return minidx;
    }
};