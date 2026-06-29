class Solution {
public:
    int digitFrequencyScore(int n) {
        int a=n;
        unordered_map<int,int> mpp;
        while(n>0){
            int l=n%10;
            mpp[l]++;
            n/=10;
        }
        int ans=0;
        for(auto it:mpp){
            ans+=(it.first*it.second);
        }
        return ans;
    }
};