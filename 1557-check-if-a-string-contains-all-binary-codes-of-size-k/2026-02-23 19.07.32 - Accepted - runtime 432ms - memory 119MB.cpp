class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_set<string> st;
        for(int i=k;i<=n;i++){
            st.insert(s.substr(i-k,k));
        }
        return st.size()==(1<<k);
    }
};