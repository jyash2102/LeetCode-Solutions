class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        double sum=nums[n-1];
        int cnt=0;
        double n1=1;
        for(int i=n-2;i>=0;i--){
            double average=sum/n1;
            if((double)nums[i]>average) cnt++;
            n1++;
            sum+=nums[i];
        }
        return cnt;
    }
};