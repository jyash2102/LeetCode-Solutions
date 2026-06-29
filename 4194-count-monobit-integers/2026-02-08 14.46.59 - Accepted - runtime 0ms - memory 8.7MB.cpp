class Solution {
public:
    int countMonobit(int n){
        int cnt=1;
        int curr=1;
        while(curr<=n){
            cnt++;
            curr=(curr<<1) | 1;
        }
        return cnt;
    }
};