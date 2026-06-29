class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int> freq;
        for(auto & it: words){
            if(it.length()>=k){
                string p=it.substr(0,k);
                freq[p]++;
            }
        }
        int ans=0;
        for(auto & it : freq){
            if(it.second>=2) ans++;
        }
        return ans;
    }
};