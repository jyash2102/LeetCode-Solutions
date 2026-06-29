class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // 1) Find the pivot index where nums[i] < nums[i + 1]
        int idx = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // If no pivot is found, the array is in descending order, so we reverse it
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2) Reverse the sequence after the pivot index to make it the smallest sequence
        reverse(nums.begin() + idx + 1, nums.end());

        // 3) Find the element just larger than nums[idx] to swap with
        int j = -1;
        for (int k = idx + 1; k < n; k++) {
            if (nums[k] > nums[idx]) {
                j = k;
                break;
            }
        }

        // 4) Swap the pivot with the just larger element
        swap(nums[idx], nums[j]);
    }
};