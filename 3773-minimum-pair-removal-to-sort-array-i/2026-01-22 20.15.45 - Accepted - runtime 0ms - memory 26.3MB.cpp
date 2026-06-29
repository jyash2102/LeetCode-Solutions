class Solution {
public:
    int solve(vector<int>& nums,int cnt){
        int n=nums.size();
        bool flag=true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                flag=false;
                break;
            }
        }
        if(flag==true) return cnt;
        int minsum=INT_MAX;
        int idx=-1;
        for(int i=0;i<n-1;i++){
            int sum=nums[i]+nums[i+1];
            if(minsum>sum){
                minsum=sum;
                idx=i;
            }
        }
        nums[idx]=minsum;
        nums.erase(nums.begin()+idx+1);
        return solve(nums,cnt+1);
    }
    int minimumPairRemoval(vector<int>& nums) {
        return solve(nums,0);
    }
};