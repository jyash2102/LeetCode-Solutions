class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip=0;
        int abit,bbit,cbit;
        while(a || b || c){
            abit = a&1;
            bbit = b&1;
            cbit = c&1;
            if(cbit){
                if(!abit && !bbit) flip++;
            }
            else{
                if(abit && bbit) flip+=2;
                else if (abit || bbit) flip++;
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flip;
    }
};