class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int operations=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=target[i] && mpp[nums[i]]==0){
                operations++;
                mpp[nums[i]]++;
            }
        }
        return operations;
    }
};