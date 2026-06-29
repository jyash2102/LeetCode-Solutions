class Solution {
public:
    bool consecutiveSetBits(int n) {
        string s=bitset<32>(n).to_string();
        s.erase(0,s.find_first_not_of('0'));
        int cnt=0;
        while(n>0){
            if((n&3)==3) cnt++;
            n>>=1;
        }
        return (cnt==1);
    }
};