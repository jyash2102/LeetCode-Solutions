class Solution {
public:
    bool isprime(int n ){
        if(n==1) return false;
        for(int i=2;i<n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    string rem(string s){
        int i=0;
        while(i<s.size() && s[i]=='0') i++;
        if(i==s.size()) return "0";
        return s.substr(i);
    }
    int sumOfPrimesInRange(int n) {
        string s=to_string(n);
        reverse(s.begin(),s.end());
        string remi=rem(s);
        int n2=stoi(remi);
        int mini=min(n,n2);
        int maxi=max(n,n2);
        int sum=0;
        for(int i=mini;i<=maxi;i++){
            if(isprime(i)) sum+=i;
        }
        return sum;
    }
};