class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int i=0,j=0;
        multiset<int> ms;
        long long ans=0;
        while(j<n){
            ms.insert(nums[j]);
            while(!ms.empty()){
                long long maxi=*ms.rbegin();
                long long mini=*ms.begin();
                long long len=j-i+1;
                if((maxi-mini)*len<=k) break;
                ms.erase(ms.find(nums[i]));
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};