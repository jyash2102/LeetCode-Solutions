class Solution {
public:
    int firstocc(vector<int>& nums, int target){
        int n = nums.size();
        int low=0,high=n-1;
        int first=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return first;
    }
    int lastocc(vector<int>& nums, int target){
        int n = nums.size();
        int low=0,high=n-1;
        int last=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        ans[0]=firstocc(nums,target);
        ans[1]=lastocc(nums,target);
        return ans;
    }
};