class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string v=s;
        sort(v.begin(),v.end());
        if(v==s) return 0;
        if(n<3) return -1;
        char mx=*max_element(s.begin(),s.end());
        char mn=*min_element(s.begin(),s.end());
        if(s[0]==mn || s[n-1]==mx) return 1;
        else if(s[0]==mx && s[n-1]==mn){
            string t1=s;
            string t2=s;
            sort(t1.begin(),t1.begin()+n-1);
            sort(t1.begin()+1,t1.end());
            sort(t2.begin()+1,t2.end());
            sort(t2.begin(),t2.begin()+n-1);
            if(v==t1 || v==t2) return 2;
            return 3;
        }
        return 2;
    }
};