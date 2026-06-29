class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int msb = -1;
        for(int i=31;i>=0;i--){
            if((n>>i)&1){
            msb = i;
            break;
            }       
        }      
        int ans=0;
        for(int i=msb;i>=0;i--){
            int bit=(n>>i)&1;
            if(!bit) ans|=(1<<i);
        }
        return ans;
    }
};