class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> v(150,0);
        for(int i=0;i<n;i++){
            int idx=s[i];
            v[idx]++;
        }
        for(int j=0;j<m;j++){
            int idx=t[j];
            v[idx]--;
        }
        int k=v.size();
        for(int j=0;j<k;j++){
            if(v[j]!=0) return false;
        }
        return true;
    }
};