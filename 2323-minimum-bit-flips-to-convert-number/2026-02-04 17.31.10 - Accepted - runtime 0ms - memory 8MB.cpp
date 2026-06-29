class Solution {
public:
    int minBitFlips(int start, int goal) {
        int XOR=start^goal;
        return __builtin_popcount(XOR);
    }
};