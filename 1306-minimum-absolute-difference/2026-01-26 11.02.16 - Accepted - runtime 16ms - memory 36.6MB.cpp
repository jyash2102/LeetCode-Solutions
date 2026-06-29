class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int minabs = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            int dif = abs(arr[i + 1] - arr[i]);
            if (minabs > dif) {
                ans.clear();
                ans.push_back({arr[i], arr[i+1]});
                minabs = dif;
            }
            else if(minabs==dif)  ans.push_back({arr[i], arr[i+1]});
        }
        return ans;
    };
};