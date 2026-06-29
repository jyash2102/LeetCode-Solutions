class Solution {
public:
    const int M = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> left,right;
        int ans=0;
        for(int i=0;i<n;i++) right[nums[i]]++;
        for(int j=0;j<n;j++){
            int x = nums[j];
            long target=(long) x*2;
            right[x]--;
            ans = (ans + ((long) left[(int) target] * right[(int) target]) % M) % M;
            left[x]++;
        }
        return (int)ans;
    }
};