class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle k >= n
        vector<int> temp;

        // Copy last k elements to temp
        for(int i = n - k; i < n; i++) {
            temp.push_back(nums[i]);
        }

        // Shift the first n-k elements to the right
        for(int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // Copy the k elements from temp to the beginning
        for(int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
