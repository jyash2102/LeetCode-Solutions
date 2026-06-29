class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
    string trimTrailingVowels(string s) {
        int n = s.length();
        int i=n-1;
        while(i>=0 && isvowel(s[i])){
            i--;
        }
            
        return s.substr(0,i+1);
    }
};