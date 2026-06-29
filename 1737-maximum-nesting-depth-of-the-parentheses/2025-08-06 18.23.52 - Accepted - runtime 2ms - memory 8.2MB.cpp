class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        long long cnt=0;
        long long depth=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }
            if(s[i]==')'){
                depth=max(cnt,depth);
                cnt--;
            }
        }
        return depth;
    }
};