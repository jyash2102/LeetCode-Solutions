class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag=true;
        int bit=-1;
        while(n>0){
            int curbit=n&1;
            if(bit!=-1 && bit==curbit){
                flag=false;
                break;
            } 
            bit=curbit;
            n>>=1;
        }
        return flag;
    }
};