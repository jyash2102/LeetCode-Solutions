class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long ans = 0;

        int i = 0;

        while (i < n) {
            if (s[i] == '0') {
                i++;
                continue;
            }

            int L = i;

            while (i < n && s[i] == '1') i++;

            int R = i - 1;

            long long sum = 0;
            int mn = INT_MAX;

            int start = max(0, L - 1);

            for (int j = start; j <= R; j++) {
                sum += nums[j];
                mn = min(mn, nums[j]);
            }

            if (L == 0) ans += sum;
            else ans += sum - mn;
        }

        return ans;
    }
};