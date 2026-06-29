class Solution {
public:
    long long oper(vector<int>& nums,int k){
        long long cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cnt+=(nums[i]+k-1)/k;
        }
        return cnt;
    }
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long low=1,high=10000000;
        long long ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if((long long)oper(nums,mid)<=1LL*mid*mid){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return (int)ans;
    }
};