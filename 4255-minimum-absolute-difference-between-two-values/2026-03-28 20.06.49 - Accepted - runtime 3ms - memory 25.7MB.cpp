class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int mdiff=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==1 && nums[j]==2 || nums[i]==2 && nums[j]==1){
                    int diff=abs(i-j);
                    mdiff=min(diff,mdiff);
                }
            }
        }
        if(mdiff==INT_MAX) return -1;
        return mdiff;
    }
};