class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1;
        int ans=INT_MIN;
        while(i<j){
            int h=min(height[i],height[j]);
            int len=j-i;
            ans=max(ans,len*h);
            if(h==height[i]) i++;
            else j--;
        }
        return ans;
    }
};