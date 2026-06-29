class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int ans=n;
        while(j<n){
            while((long long)nums[j]>(long long)nums[i]*k){
                i++;
            }
            ans=min(ans,n-(j-i+1));
            j++;
        }
        return ans;
    }
};