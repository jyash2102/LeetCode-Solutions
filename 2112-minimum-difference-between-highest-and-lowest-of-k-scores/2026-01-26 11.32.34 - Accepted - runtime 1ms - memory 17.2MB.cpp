class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1) return 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(k==n) return (nums[n-1]-nums[0]);
        int mindif=INT_MAX;
        int i=0;
        for(int j=0;j<n;j++){
            while((j-i)+1>k) i++;
            if(j-i+1==k){
                int diff=nums[j]-nums[i];
                mindif=min(diff,mindif);
            }
        }
        return mindif;
    }
};