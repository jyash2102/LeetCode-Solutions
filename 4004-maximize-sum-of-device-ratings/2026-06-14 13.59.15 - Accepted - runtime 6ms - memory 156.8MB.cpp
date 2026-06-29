class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size();
        int m = units[0].size();
        long long  ans=0;
        int mini=1e9;
        int mini2=1e9;
        if (m == 1) {
            for (int i = 0; i < n; i++) {
                ans += units[i][0];
            }
            return ans;
        }
        for(int i=0;i<n;i++){
            int min2=1e9;
            int min1=1e9;
            for(int j=0;j<m;j++){
                if(units[i][j]<min1){
                    min2=min1;
                    min1=units[i][j];
                }
                else if(units[i][j]<min2) min2=units[i][j];
            }
            ans+=min2;
            mini=min(mini,min1);
            mini2=min(mini2,min2);
        }
        ans+=mini;
        ans-=mini2;
        return (long long)ans;
    }
};