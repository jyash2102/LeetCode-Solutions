class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int total=0;
        int i=0;
        while (i<n) {
            char c = colors[i];
            int maxTime = 0;
            int sumTime = 0;
            while (i < n && colors[i] == c) {
                sumTime += neededTime[i];
                maxTime = max(maxTime, neededTime[i]);
                i++;
            }
            total += (sumTime - maxTime);
        }
        return total;
    }
};