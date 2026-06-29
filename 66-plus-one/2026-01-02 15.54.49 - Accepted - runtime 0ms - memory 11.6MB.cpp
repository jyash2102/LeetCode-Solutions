class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n - 1;
        while (digits[i] == 9 && i != 0) {
            digits[i] = 0;
            i--;
        }
        if (i == 0 && digits[i] == 9) {
            digits[i] = 0;
            digits.emplace(digits.begin(), 1);
        } else
            digits[i] += 1;

        return digits;
    }
};