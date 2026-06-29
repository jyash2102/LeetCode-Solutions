class Solution {
public:    
    int minimizeXor(int num1, int num2) {
        if(__builtin_popcount(num1)==__builtin_popcount(num2)) return num1;
        if(__builtin_popcount(num1)>__builtin_popcount(num2)){
            while(__builtin_popcount(num1)!=__builtin_popcount(num2)){
                num1=num1&(num1-1);
            }
            return num1;
        }
        if(__builtin_popcount(num1)<__builtin_popcount(num2)){
            while(__builtin_popcount(num1)!=__builtin_popcount(num2)){
                num1=num1|(num1+1);
            }
            return num1;
        }
        return num1;
    }
};