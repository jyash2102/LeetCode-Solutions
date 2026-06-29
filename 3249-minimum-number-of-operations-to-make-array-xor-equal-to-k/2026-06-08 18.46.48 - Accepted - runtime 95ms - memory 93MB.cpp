class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int XOR=0;
        for(int i=0;i<n;i++){
            XOR^=nums[i];
        }
        return __builtin_popcount(XOR^k);
    }
};