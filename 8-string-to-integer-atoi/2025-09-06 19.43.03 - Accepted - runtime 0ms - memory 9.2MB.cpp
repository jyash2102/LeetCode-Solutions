class Solution {
public:
    int helper(string &s, int i, long long result, int sign) {
        if (i >= s.size() || !isdigit(s[i])) return sign * result;
        int digit = s[i] - '0';
        result = result * 10 + digit;
        if (sign * result >= INT_MAX) return INT_MAX;
        if (sign * result <= INT_MIN) return INT_MIN;
        return helper(s, i + 1, result, sign);
    }

    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        return helper(s, i, 0, sign);
    }
};
