class Solution {
public:
    int M=1e9+7;
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long sum=0;
        int i=n-1;
        while(i>=0 && k>0){
            if(mul>0){
                sum+=nums[i]*(long long)mul;
                mul--;
            }
            else if(mul==0) sum+=nums[i];
            i--;
            k--;
        }
        return sum;
    }
};