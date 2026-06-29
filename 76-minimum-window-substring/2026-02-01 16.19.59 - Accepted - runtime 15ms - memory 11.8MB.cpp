class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        unordered_map<char,int> tpp;
        for(int i=0;i<t.length();i++) tpp[t[i]]++;
        int i=0,j=0;
        int req=0;
        unordered_map<char,int> mpp;
        int minlen=INT_MAX;
        int start=-1;
        while(j<s.length()){
            mpp[s[j]]++;
            if(tpp.count(s[j]) && mpp[s[j]]==tpp[s[j]]) req++;
            while(req==tpp.size()){
                if(j-i+1<minlen){
                    minlen=j-i+1;
                    start=i;
                }
                mpp[s[i]]--;
                if(tpp.count(s[i]) && mpp[s[i]]<tpp[s[i]]) req--;
                i++;
            }
            j++;
        }
        if(minlen==INT_MAX) return "";
        return s.substr(start,minlen);
    }
};