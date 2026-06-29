class Solution {
public:
    string maximumXor(string s, string t) {
        int ones=0,zeroes=0;
        for(char c:t){
            if(c=='1') ones++;
            else zeroes++;
        }
        string result="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                if(zeroes>0){
                    result+='1';
                    zeroes--;
                }
                else{
                    result+='0';
                    ones--;
                }
            }else{
                if(ones>0){
                    result+='1';
                    ones--;
                }
                else{
                    result+='0';
                    zeroes--;
                }
            }
        }
        return result;
    }
};