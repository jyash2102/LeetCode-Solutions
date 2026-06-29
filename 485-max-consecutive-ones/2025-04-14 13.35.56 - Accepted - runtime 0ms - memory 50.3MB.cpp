class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0,a=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
                if(count>a) a=count;
            }
            else{
                count=0;
                continue;
            }
        }
        return a;
    }
};