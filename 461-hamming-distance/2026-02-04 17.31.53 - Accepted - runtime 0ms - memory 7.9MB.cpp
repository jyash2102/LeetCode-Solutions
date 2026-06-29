class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR=x^y;
        return __builtin_popcount(XOR);
    }
};