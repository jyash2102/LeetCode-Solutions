class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> specials;
        int n = s.length();
        int balance=0;
        int start=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') balance+=1;
            else balance-=1;
            if(balance==0){
                specials.push_back("1"+makeLargestSpecial(s.substr(start+1,i-start-1))+"0");
                start=i+1;
            }
        }
        sort(begin(specials),end(specials),greater<string>());
        string result;
        for(string& str:specials){
            result+=str;
        }
        return result;
    }
};