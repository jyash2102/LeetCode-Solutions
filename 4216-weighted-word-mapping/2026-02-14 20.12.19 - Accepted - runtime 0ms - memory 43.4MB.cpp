class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        int n = weights.size();
        for(int i=0;i<words.size();i++){
            string s=words[i];
            int sum=0;
            for(int j=0;j<s.length();j++){
                sum+=weights[s[j]-'a'];
            }
            sum=sum%26;
            int idx=(25-sum)%26;
            char el='a'+idx;
            ans.push_back(el);
        }
        return ans;
    }
};