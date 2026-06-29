class Solution {
public:
    bool check(int n){
        if(n==1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int prime=0;
        for(int i=left;i<=right;i++){
            if(check(__builtin_popcount(i))) prime++;
        }
        return prime;
    }
};