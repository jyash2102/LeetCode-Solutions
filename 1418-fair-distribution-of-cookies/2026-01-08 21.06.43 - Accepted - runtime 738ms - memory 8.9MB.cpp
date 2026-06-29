class Solution {
public:
    void distribute(int idx,vector<int>& cookies,vector<int>& v,int k,int& ans){
        if(idx==cookies.size()){
            int unfairness=*max_element(begin(v),end(v));
            ans=min(ans,unfairness);
            return;
        }
        int cookie=cookies[idx];
        for(int i=0;i<k;i++){
            v[i]+=cookie;
            distribute(idx+1,cookies,v,k,ans);
            v[i]-=cookie;
        }
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k,0);
        int ans=INT_MAX;
        distribute(0,cookies,v,k,ans);
        return ans;
    }
};