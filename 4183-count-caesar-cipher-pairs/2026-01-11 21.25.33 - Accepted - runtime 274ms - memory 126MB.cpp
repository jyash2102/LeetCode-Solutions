class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string,long long> mpp;
        for(auto& s1 : words){
            string s="";
            for(int i=1;i<s1.length();i++){
                int d=((s1[i]-s1[i-1])+26)%26;
                s+=to_string(d)+'#';
            }
            mpp[s]++;
        }
        long long ans=0;
        for(auto& x:mpp){
            long long k=x.second;
            ans+=k*(k-1)/2;
        }
        return ans;
    }
};