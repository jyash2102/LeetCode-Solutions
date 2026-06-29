class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int i = 0, maxlen = 0;

        for (int j = 0; j < s.length(); j++) {
            mpp[s[j]]++;

            // If duplicate found, shrink window
            while (mpp[s[j]] > 1) {
                mpp[s[i]]--;
                i++;
            }

            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};
