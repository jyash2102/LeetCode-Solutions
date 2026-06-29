class Solution {
public:
    int minCost(int n) {
        if(n==0) return 0;
        int ans=0;
        while(n!=1){
            n-=1;
            ans+=n;
        }
        return ans;
    }
};