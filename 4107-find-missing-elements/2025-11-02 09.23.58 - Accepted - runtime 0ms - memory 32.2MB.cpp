class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        if (nums.empty()) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            int prev = nums[i - 1];
            int curr = nums[i];
            if (curr == prev) continue;
            for (int j = prev + 1; j < curr; j++) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};
