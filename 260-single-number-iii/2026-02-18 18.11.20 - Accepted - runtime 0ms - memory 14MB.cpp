class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long XORall=0;
        for(int i=0;i<n;i++){
            XORall^=nums[i];
        }
        int b1=0;
        int b2=0;
        long rightmost=(XORall&(XORall-1))^XORall;
        for(int i=0;i<n;i++){
            if(nums[i] & rightmost)  b1=b1^nums[i];
            else b2=b2^nums[i];
        }
        return{b1,b2};
    }
};