class Solution {
public:
    void generate(vector<vector<int>>& ans, vector<int>& v, vector<int>& nums,
                  vector<int>& visited) {

        if (v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            
            if (visited[i])
                continue;

            
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;

            visited[i] = 1;
            v.push_back(nums[i]);

            generate(ans, v, nums, visited);

            v.pop_back();
            visited[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // VERY IMPORTANT
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> visited(nums.size(), 0);

        generate(ans, v, nums, visited);
        return ans;
    }
};
