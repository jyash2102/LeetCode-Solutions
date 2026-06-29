class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0,j=0;
        int maxfreq=1;
        long long sum=0;
        while(j<n){
            sum+=nums[j];
            while((long long)(j-i+1)*nums[j]-sum>k){
                sum-=nums[i];
                i++;
            }
            maxfreq=max(maxfreq,j-i+1);
            j++;
        }
        return maxfreq;
    }
};