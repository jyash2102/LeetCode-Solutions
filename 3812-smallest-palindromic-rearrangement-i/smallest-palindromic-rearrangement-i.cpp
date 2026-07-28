class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> mpp(26,0);
        string left;
        for(int i=0;i<n/2;i++) mpp[s[i]-'a']++;
        for(int i=0;i<26;i++){
            while(mpp[i]>0){
                left.push_back((char)'a'+i);
                mpp[i]--;
            }
        }
        string ans=left;
        if(n%2) ans.push_back(s[n/2]);
        reverse(left.begin(),left.end());
        ans+=left;
        return ans;
    }
};