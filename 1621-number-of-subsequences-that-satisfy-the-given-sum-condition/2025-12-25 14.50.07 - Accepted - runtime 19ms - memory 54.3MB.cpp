class Solution {
public:
    const int M=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=n-1;
        long long cnt=0;
        vector<int> power(n);
        power[0]=1;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%M;
        }
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                cnt=(cnt+power[j-i])%M;
                i++;
            }
            else j--;
        }
        return (int)cnt;
    }
};