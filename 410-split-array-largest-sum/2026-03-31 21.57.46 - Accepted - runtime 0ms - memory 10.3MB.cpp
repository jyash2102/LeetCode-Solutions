class Solution {
public:
    bool isvalid(vector<int>& nums, int k,int mid){
        int n = nums.size();
        int cnt=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>mid) return false;
            if(sum+nums[i]>mid){
                cnt++;
                sum=nums[i];
            }
            else sum+=nums[i];
        }
        return (cnt<=k);
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low=*min_element(nums.begin(),nums.end()),high=accumulate(nums.begin(), nums.end(), 0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isvalid(nums,k,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};