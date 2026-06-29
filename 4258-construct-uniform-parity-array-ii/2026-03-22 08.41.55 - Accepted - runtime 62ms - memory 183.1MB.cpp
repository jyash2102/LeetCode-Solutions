class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> mpp1;
        vector<int> mpp2;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0) mpp1.push_back(nums1[i]);
            else mpp2.push_back(nums1[i]);
        }
        sort(mpp1.begin(),mpp1.end());
        sort(mpp2.begin(),mpp2.end());
        if(mpp1.empty() || mpp2.empty()) return true;
        if(mpp1[0]>mpp2[0]) return true;
        return false;
    }
};