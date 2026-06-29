class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            int dx=abs(points[i+1][0]-points[i][0]);
            int dy=abs(points[i+1][1]-points[i][1]);
            cnt+=max(dx,dy);
        }
        return cnt;
    }
};