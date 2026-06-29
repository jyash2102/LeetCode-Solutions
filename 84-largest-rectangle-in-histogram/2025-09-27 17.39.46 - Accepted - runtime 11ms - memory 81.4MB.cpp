class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int nse,pse,el;
        int area=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                nse=i;
                el=st.top();
                st.pop();
                if(!st.empty()) pse=st.top();
                else pse=-1;
                int width=(nse-pse)-1;
                area = max(area,(heights[el]*width));
            }
            st.push(i);
        }
        while(!st.empty()){
            el=st.top();
            st.pop();
            if(!st.empty()) pse=st.top();
            else pse=-1;
            nse=n;
            int width=(nse-pse)-1;
            area = max(area,(heights[el]*width));
        }
        return area;
    }
};