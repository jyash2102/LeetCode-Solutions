class Solution {
#define ll long long
public:
    bool solve(ll mid,vector<ll>& bonus,vector<int>& monsters){
        int n = monsters.size();
        for(int i=0;i<n;i++){
            if(mid+bonus[i]>=monsters[i]){
                mid=max((ll)0,mid-(ll)monsters[i]);
            }
            else return false;
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<ll> diff(n+1,0);
        for(auto& v:boosts){
            diff[v[0]]+=(ll)v[2];
            diff[v[1]+1]-=(ll)v[2];
        }
        vector<ll> bonus(n,0);
        ll running=0;
        for(int i=0;i<n;i++){
            running+=diff[i];
            bonus[i]=running;
        }
        ll low=0;
        ll high=0;
        for(int i=0;i<n;i++) high+=(ll)monsters[i];
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(solve(mid,bonus,monsters)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};