class Solution {
public:
    int binaryGap(int n) {
        int maxgap=INT_MIN;
        int gap=0;
        int flag=false;
        while(n){
            int bit=n&1;
            if(flag) gap++;
            if(bit){
                maxgap=max(maxgap,gap);
                gap=0;
                flag=true;
            }
            n>>=1;
        }
        return (maxgap==INT_MIN) ? 0 : maxgap;
    }
};