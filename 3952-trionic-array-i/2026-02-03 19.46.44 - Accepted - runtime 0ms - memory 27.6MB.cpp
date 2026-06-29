class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int p=0;
        int q=0;
        bool inc=true;
        bool dec=true;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) return false;
            if(inc && nums[i]<nums[i+1]){
                p++;
                inc=false;
                dec=true;
            }
            if(dec && nums[i]>nums[i+1]){
                q++;
                dec=false;
                inc=true;
            }
        }
        if(p==2 && q==1) return true;
        return false;
    }
};