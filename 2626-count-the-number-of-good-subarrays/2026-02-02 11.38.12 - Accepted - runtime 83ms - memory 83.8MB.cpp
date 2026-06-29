class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n =nums.size();
        int i=0,j=0;
        long long pairs=0;
        long long cnt=0;
        unordered_map<long long,long long> mpp;
        while(j<n){
            pairs+=mpp[nums[j]];
            mpp[nums[j]]++;
            while(i<=j && pairs>=k){
                cnt+=(n-j);
                mpp[nums[i]]--;
                pairs-=mpp[nums[i]];
                i++;
            }
            j++;
        }
        return cnt;
    }
};