class Solution {
public:
    string mergeCharacters(string s, int k) {
        while(true){
            bool flag=false;
            for(int i=0;i<s.length();i++){
                for(int j=i+1;j<s.length();j++){
                    if(j-i>k) break;
                    if(s[i]==s[j]){
                        s.erase(j,1);
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag==false) break;
        }
        return s;
    }
};