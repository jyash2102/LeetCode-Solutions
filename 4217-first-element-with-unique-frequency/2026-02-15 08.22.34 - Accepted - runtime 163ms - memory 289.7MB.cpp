class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        unordered_map<int,int> freq;
        for(auto& it: mpp){
            freq[it.second]++;
        }
        for(int i=0;i<n;i++){
            if(freq[mpp[nums[i]]]==1) return nums[i];
        }
        return -1;
    }
};