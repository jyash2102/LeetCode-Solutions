class Solution {
public:
    int minimumFlips(int n) {
        string s="";
        while(n>0){
            s=char((n%2)+'0')+s;
            n/=2;
        }
        int operation=0;
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i] != s[j]) operation+=2;
            i++;
            j--;
        }
        return operation;
    }
};