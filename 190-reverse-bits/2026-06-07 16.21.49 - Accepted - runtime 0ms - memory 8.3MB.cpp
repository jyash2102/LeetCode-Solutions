class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int bit=31;bit>=0;bit--){
            if((n>>bit)&1){
                ans|=(1<<(31-bit));
            }
        }
        return ans;
    }
};