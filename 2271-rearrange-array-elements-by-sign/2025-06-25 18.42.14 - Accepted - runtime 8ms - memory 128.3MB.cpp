class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int l=0,k=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                v[l]=nums[i];
                l+=2;
            }
            else{
                v[k]=nums[i];
                k+=2;
            }
        }
        return v;
    }
};