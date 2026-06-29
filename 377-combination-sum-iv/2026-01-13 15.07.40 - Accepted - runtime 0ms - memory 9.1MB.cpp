class Solution {
public:
    vector<int> dp;

    int generate(vector<int>& nums, int target) {
        if (target == 0) return 1;
        if (dp[target] != -1) return dp[target];

        int cnt = 0;
        for (int x : nums) {
            if (x <= target)
                cnt += generate(nums, target - x);
        }
        return dp[target] = cnt;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target + 1, -1);
        return generate(nums, target);
    }
};
