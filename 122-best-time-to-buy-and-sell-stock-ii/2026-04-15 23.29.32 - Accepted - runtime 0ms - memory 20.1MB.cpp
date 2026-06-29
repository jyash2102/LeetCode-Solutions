class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit=0;
        int diff=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]-diff>0){
                profit+=prices[i]-diff;
                diff=prices[i];
            }
            else{
                diff=prices[i];
            }
        }
        return profit;
    }
};