class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        long long maxGain=0;
        long long iprofit=0;
        vector<long long> profit(n);
        for(int i=0;i<n;i++){
            profit[i]=prices[i]*strategy[i];
            iprofit+=profit[i];
        }
        long long initialProfit=0;
        long long modifiedProfit=0;
        int i=0;
        int j=0;
        while(j<n){
            initialProfit+=profit[j];
            if(j-i+1>k/2){
                modifiedProfit+=prices[j];
            }
            if(j-i+1>k){
                initialProfit-=profit[i];
                modifiedProfit-=prices[i+k/2];
                i++;
            }
            if(j-i+1==k) maxGain=max(maxGain,(modifiedProfit-initialProfit));
            j++;
        }
        return iprofit+maxGain;
    }
};