class Solution {
public:
    //calculation no. of subarrays<=k;
    int Subarrays(vector<int>& nums, int k){
        if(k<0) return 0;
        int n = nums.size();
        int i=0;
        int j=0;
        int cnt=0;
        int odd=0;
        while(j<n){
            if(nums[j]%2==1) odd++;
            while(odd>k){
                if(nums[i]%2==1) odd--;
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return Subarrays(nums,k)-Subarrays(nums,k-1);
    }
};