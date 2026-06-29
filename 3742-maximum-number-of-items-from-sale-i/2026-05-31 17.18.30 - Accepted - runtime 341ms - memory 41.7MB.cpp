class Solution {
public:
    int dp[1000][1501];
    int mini=1e9;
    int recur(int idx, int budget,vector<vector<int>>& items,vector<int>& divi){
        if(idx>=items.size()) return budget/mini;
        if(dp[idx][budget]!=-1) return dp[idx][budget];

        int take=0;
        if(budget>=items[idx][1]) {
            take=divi[idx]+recur(idx+1, budget-items[idx][1], items,divi);
        }

        int skip=recur(idx+1, budget, items,divi);
        return dp[idx][budget]=max(take, skip);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> divi(n,1);
        for(int i=0;i<n;i++){
            mini=min(mini,items[i][1]);
            for(int j=0;j<n;j++){
                if(i != j && items[j][0] % items[i][0] == 0) divi[i]++;
            }
        }
        memset(dp, -1, sizeof(dp));
        return recur(0,budget,items,divi);
    }
};