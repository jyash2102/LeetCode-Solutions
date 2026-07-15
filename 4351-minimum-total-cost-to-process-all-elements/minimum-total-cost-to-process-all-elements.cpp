class Solution {
#define ll long long 
public:
    int M = 1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        ll cost=0;
        ll cnt=0;
        int curr=k;
        for(int i=0;i<nums.size();i++){
            if(curr<nums[i]){
                double diff=nums[i]-curr;
                int op=ceil((double)diff/k);
                ll c = (1LL * op * cnt) % M;
                c = (c + (1LL * op * (op + 1) / 2)) % M;
                cost=(cost+c)%M;
                curr+=op*k;
                cnt=(cnt+op)%M;
            }
            curr-=nums[i];
        }
        return (int)cost;
    }
};