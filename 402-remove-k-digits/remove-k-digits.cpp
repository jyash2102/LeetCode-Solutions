class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        string s;
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
            reverse(s.begin(),s.end());
            int idx=0;
            while(s[idx]=='0') idx++;
            s.erase(0,idx);
        if(s.empty()) s.push_back('0');
        return s;
    }
};