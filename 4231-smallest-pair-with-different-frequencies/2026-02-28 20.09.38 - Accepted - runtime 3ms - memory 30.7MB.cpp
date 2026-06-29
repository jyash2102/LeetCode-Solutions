class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int s=mpp.begin()->first;
        int freq=mpp.begin()->second;
        vector<int> ans;
        for(auto& it : mpp){
            if(it.first==s) continue;
            int el=it.first;
            int f=it.second;
            if(freq==f) continue;
            else return {s,el};
        }
        if(ans.empty()) return {-1,-1};
        return ans;
    }
};