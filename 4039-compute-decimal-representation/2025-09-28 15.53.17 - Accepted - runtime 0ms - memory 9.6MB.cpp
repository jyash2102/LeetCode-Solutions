class Solution {
public:
    vector<int> decimalRepresentation(int n) {
       vector<int> ans;
       int l,anss;
       long long r=1;
       while(n>0){
        l=n%10;
        anss=r*l;
        if(anss!=0) ans.push_back(anss);
        r=(long long)r*10;
        n=n/10;
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};