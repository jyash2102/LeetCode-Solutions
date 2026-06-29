class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int waviness=0;
        string s;
        for(int i=num1;i<=num2;i++){
            s=to_string(i);
            int n = s.length();
            if(n<3) continue;
            for(int j=1;j<=n-2;j++){
                int u=s[j-1] - '0';
                int v=s[j]-'0';
                int w=s[j+1]-'0';
                if((v>u && v>w) || (v<u && v<w)) waviness++;
            }
        }
        return waviness;
    }
};