class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int n=happiness.size();
        int j=n-1;
        long long hap=0;
        int cnt=0;
        while(j>=0 && k>0){
           long long curr = max(0LL, (long long)happiness[j] - cnt);
            hap += curr;
            cnt++;
            j--;
            k--;
        }
        return hap;
    }
};