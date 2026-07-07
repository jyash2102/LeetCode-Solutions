class Solution {
#define ll long long
public:
    long long sumAndMultiply(int n) {
        ll mul=1;
        ll num=0;
        ll sum=0;
        while(n>0){
            ll l=n%10;
            if(l==0){
                n/=10;
                continue;
            }
            sum+=l;
            l*=mul;
            num+=l;
            mul*=10;
            n/=10;
        }
        return num*sum;
    }
};