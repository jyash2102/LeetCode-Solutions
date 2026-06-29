class Solution {
public:
    const int M = 1e9+7;
    int concatenatedBinary(int n) {
        long long ans=0;
        int bitlength=0;
        for(int i=1;i<=n;i++){
            bitlength=log2(i)+1;
            ans=((ans<<bitlength)%M+i)%M;
        }
        return ans;
    }
};