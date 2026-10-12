#define ll long long
class Solution {
public:
    int M=1e9+7;
    int power(ll a,ll b){
        if(b==0) return 1;
        int half=power(a,b/2);
        if(b%2){
            return ((a*half)%M*half)%M;
        }
        return ((ll)half*half)%M;
    }
    int countGoodNumbers(long long n) {
        int even=power(5,(n+1)/2);
        int odd=power(4,n/2);
        return ((ll)even*odd)%M;
    }
};