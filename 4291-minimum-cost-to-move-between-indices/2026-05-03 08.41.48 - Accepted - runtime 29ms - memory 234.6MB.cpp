class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> closest(n);
        for(int i=0;i<n;i++){
            if(i==0) closest[i]=1;
            else if(i==n-1) closest[i]=n-2;
            else{
                int left=nums[i]-nums[i-1];
                int right=nums[i+1]-nums[i];
                if(left<=right) closest[i]=i-1;
                else closest[i]=i+1;
            }
        }
        vector<long long> pref(n,0);
        for(int i=1;i<n;i++){
            if(closest[i-1]==i) pref[i]=pref[i-1]+1;
            else{
                pref[i]=pref[i-1]+(nums[i]-nums[i-1]);
            }
        }
        vector<long long> suff(n,0);
        for(int i=n-2;i>=0;i--){
            if(closest[i+1]==i) suff[i]=suff[i+1]+1;
            else{
                suff[i]=suff[i+1]+(nums[i+1]-nums[i]);
            }
        }
        vector<int> ans;
        for(auto& q : queries){
            int l=q[0],r=q[1];
            if(l<r) ans.push_back(pref[r]-pref[l]);
            else ans.push_back(suff[r]-suff[l]);
        }
        return ans;
    }
};