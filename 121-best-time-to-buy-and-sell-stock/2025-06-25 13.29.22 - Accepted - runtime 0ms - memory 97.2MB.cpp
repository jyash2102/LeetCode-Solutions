class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit=0,buy=prices[0];
        for(int i=1;i<n;i++){
            int profit=prices[i]-buy;
            maxprofit=max(maxprofit,profit);
            buy=min(prices[i],buy);
        }
    return maxprofit;
    }
};