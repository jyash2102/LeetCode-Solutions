class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest=0;
        int n = gain.size();
        int prev=0;
        for(int i=0;i<n;i++){
            highest=max(highest,prev+gain[i]);
            prev=prev+gain[i];
        }
        return highest;
    }
};