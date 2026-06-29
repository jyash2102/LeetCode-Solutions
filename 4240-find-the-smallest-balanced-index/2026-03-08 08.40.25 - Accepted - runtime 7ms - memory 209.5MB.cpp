class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long> suff(n + 1, 1);
        long long INF = 1e15;
        for (int i = n - 1; i >= 0; i--) {
            __int128_t prod = (__int128_t)suff[i + 1] * nums[i];
            if (prod > INF) suff[i] = INF;
            else if (prod < -INF) suff[i] = -INF;
            else suff[i] = prod;
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum == suff[i + 1]) return i;
            sum += nums[i];
        }
        return -1;
    }
};