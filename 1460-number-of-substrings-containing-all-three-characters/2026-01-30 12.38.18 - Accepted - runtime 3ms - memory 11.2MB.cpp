class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int i=0,j=0;
        vector<int> freq(3);
        int cnt=0;
        while(j<n){
            freq[s[j]-'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                cnt+=(n-j);
                freq[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};