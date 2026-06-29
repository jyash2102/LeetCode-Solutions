class Solution {
public:
    long long result(vector<int>& v, int mid){
        int n = v.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)v[i] / mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans=-1;
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(result(nums,mid)<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low = mid + 1;
            }
        }
         return ans;
    }
};