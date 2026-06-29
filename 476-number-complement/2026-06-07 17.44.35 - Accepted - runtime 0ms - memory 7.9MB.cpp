class Solution {
public:
    int findComplement(int num) {
        int msb = -1;
        for(int i=31;i>=0;i--){
            if((num>>i)&1){
            msb = i;
            break;
            }       
        }      
        int ans=0;
        for(int i=msb;i>=0;i--){
            int bit=(num>>i)&1;
            if(!bit) ans|=(1<<i);
        }
        return ans;
    }
};