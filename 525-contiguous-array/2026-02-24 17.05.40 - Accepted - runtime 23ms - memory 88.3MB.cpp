class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int maxlen=0;
        int sum=0;
        mpp[0]=-1;
        
        for(int i=0;i<n;i++){
            int s= nums[i] ? 1 : -1;
            sum+=s;
            if(mpp.find(sum)!=mpp.end()){
                maxlen=max(maxlen,i-mpp[sum]);
            }
            else{
                mpp[sum]=i;
            }
        }
        return maxlen;
    }
};