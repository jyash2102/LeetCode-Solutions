class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum=0,maxsum=INT_MIN;
        int i=0;
        while(i<n){
            sum+=nums[i];
            maxsum=max(sum,maxsum);
            if(sum<0) sum=0;
            i++;
        }
        return maxsum;
    }
};