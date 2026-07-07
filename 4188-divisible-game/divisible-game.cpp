class Solution {
#define ll long long
public:
    int M=1e9+7;
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            int num=nums[i];
            for(int j=1;j<=sqrt(num);j++){
                if(num%j==0){
                    if(j>1) st.insert(j);
                    if(num/j>1) st.insert(num/j);
                }
            }
        }
        int missingk=2;
        while(st.count(missingk)){
            missingk++;
        }
        vector<ll> candidates(st.begin(),st.end());
        candidates.push_back(missingk);
        sort(candidates.begin(),candidates.end());
        ll maxdiff=-1e18;
        ll mink=-1;
        for(ll k:candidates){
            ll maxsum=-1e18;
            ll sum=0;
            for(auto num : nums){
                ll val=(num%k==0) ? (ll)num:(ll)-num;
                sum+=val;
                maxsum=max(sum,maxsum);
                if(sum<0) sum=0;
            }
            if(maxsum>maxdiff){
                maxdiff=maxsum;
                mink=k;
            }
            else if(maxsum==maxdiff){
                if(mink==-1 || k<mink) mink=k;
            }
        }
        ll ans=((maxdiff%M) * (mink%M))%M;
        if(ans<0) ans+=M;
        return (int)ans;
    }
};