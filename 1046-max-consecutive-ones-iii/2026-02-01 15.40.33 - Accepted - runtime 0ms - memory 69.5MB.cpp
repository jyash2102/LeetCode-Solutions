class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int zeroCnt=0;
        int maxlen=INT_MIN;
        while(j<n){
            if(nums[j]==0){
                zeroCnt++;
            }
            while(zeroCnt>k){
                if(nums[i]==0) zeroCnt--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};