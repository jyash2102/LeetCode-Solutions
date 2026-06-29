class Solution {
public:
    int ans=0;
    void check(int cnt,int idx,int n,vector<vector<int>>& requests,vector<int>& v){
            if (cnt + (requests.size() - idx) <= ans) return;
            bool allzero=true;
            for(int &x :v){
                if(x!=0){
                    allzero=false;
                    break;
                }
            }
            if(allzero==true) ans=max(ans,cnt);
        for(int i=idx;i<requests.size();i++){
            int from=requests[i][0];
            int to=requests[i][1];
            v[from]--;
            v[to]++;
            check(cnt+1,i+1,n,requests,v);
            v[from]++;
            v[to]--;
        }
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> v(n,0);
        check(0,0,n,requests,v);
        return ans;
    }
};