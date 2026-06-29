class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0 && mp[nums[i]]==1){
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};