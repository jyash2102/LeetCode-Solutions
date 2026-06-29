class Solution {
public:
    int fact(int n){
        if(n<=1) return 1;
        return n*fact(n-1);
    }
    bool check(int x){
        int o=x;
        int sum=0;
        while(x>0){
            int l=x%10;
            sum+=fact(l);
            x/=10;
        }
        if(sum==o) return true;
        return false;
    }
    bool isDigitorialPermutation(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        do{
            if(s[0]=='0') continue;
            int num=stoi(s);
            if(check(num)) return true;
        }while(next_permutation(s.begin(),s.end()));
        return false;
    }
};