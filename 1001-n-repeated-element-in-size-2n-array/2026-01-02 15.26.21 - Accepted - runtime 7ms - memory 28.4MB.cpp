class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]==nums[1]) return nums[(n/2) -1];
        else return nums[n/2];
    }
};