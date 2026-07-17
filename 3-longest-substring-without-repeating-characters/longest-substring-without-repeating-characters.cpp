class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mpp;
        int i=0;
        int j=0;
        int maxlen=0;
        while(j<n){
            mpp[s[j]]++;
            while(i<j && mpp[s[j]]>1){
                mpp[s[i]]--;
                i++;
            }
            maxlen=max(j-i+1,maxlen);
            j++;
        }
        return maxlen;
    }
};