class Solution {
public:
    void generate(string digits,vector<string>& mp,vector<string>& ans,string s,int idx){
        if(idx>=digits.length()){
            ans.push_back(s);
            return;
        }
        int num=digits[idx]-'0';
        string value=mp[num];
        for(int i=0;i<value.length();i++){
            s.push_back(value[i]);
            generate(digits,mp,ans,s,idx+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string s;
        generate(digits,mp,ans,s,0);
        return ans;
    }
};