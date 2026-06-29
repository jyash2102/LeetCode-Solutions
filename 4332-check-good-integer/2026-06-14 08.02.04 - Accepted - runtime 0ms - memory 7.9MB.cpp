class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum=0;
        int sqsum=0;
        while(n>0){
            int l=n%10;
            sqsum+=(l*l);
            sum+=l;
            n/=10;
        }
        if(sqsum-sum>=50) return true;
        return false;
    }
};