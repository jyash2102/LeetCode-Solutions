class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int k=1;k<=n;k++){
            int c=k;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(sqrt(((i*i)+(j*j)))==c) cnt++;
                }
            }
        }
        return cnt;
    }
};