class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i=0;
        int cnt=0;
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(sum>goal){
                if(nums[i]==1) sum--;
                i++;
            }
            if(sum==goal){
                if(goal == 0) {
                    cnt += (j - i + 1);
                }else {
                    int zerocnt = 0;
                    int idx = i;
                    while (idx <= j && nums[idx] == 0) {
                        zerocnt++;
                        idx++;
                    }
                    cnt += zerocnt + 1;
                }
            }
        }
        return cnt;
    }
};