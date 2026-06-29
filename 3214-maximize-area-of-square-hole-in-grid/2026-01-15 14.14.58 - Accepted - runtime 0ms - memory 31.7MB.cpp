class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int h=1;
        int maxh=1;//longest consecutive sequence
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]==1) h++;
            else h=1;
            maxh=max(maxh,h);
        }
        int v=1;
        int maxv=1;//longest consecutive sequence
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]==1) v++;
            else v=1;
            maxv=max(maxv,v);
        }
        int side=min(maxh+1,maxv+1);
        return side*side;
    }
};