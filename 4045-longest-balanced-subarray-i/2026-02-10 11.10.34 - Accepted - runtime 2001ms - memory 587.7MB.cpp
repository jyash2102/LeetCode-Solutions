class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp(n);
            int o=0;
            int e=0;
            for(int j=i;j<n;j++){
                if(mpp.find(nums[j])==mpp.end() && nums[j]%2==0) e++;
                if(mpp.find(nums[j])==mpp.end() && nums[j]%2==1) o++;
                mpp[nums[j]]++;
                if(o==e) maxlen=max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
};