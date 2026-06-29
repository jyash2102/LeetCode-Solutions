class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            mp[nums1[i]]++;
            mp[nums2[i]]--;
        }
        int swaps = 0;
           for(auto&it : mp){
               if(it.second%2!=0) return -1;
               swaps+=abs(it.second)/2;
           }
        return swaps/2;
    }
};