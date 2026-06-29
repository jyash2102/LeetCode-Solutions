class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int> mp;
        string s=to_string(n);
        for(int i=0;i<s.length();i++){
            mp[s[i]-'0']++;
        }
        int mine=INT_MAX,no=-1;
        for(auto& it:mp){
            if(it.second==mine){
                mine=it.second;
                no=min(it.first,no);
            }
            if(it.second<mine){
                mine=it.second;
                no=it.first;
            }
        }
        return no;
    }
};