class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int nse,pse,el;
        int area=0;
        vector<int> heights(m, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            stack<int> st;
            for(int j=0;j<m;j++){
                while(!st.empty() && heights[st.top()]>heights[j]){
                nse=j;
                el=st.top();
                st.pop();
                if(!st.empty()) pse=st.top();
                else pse=-1;
                int width=(nse-pse)-1;
                area = max(area,(heights[el]*width));
                }
                st.push(j);
            }
            while(!st.empty()){
                el=st.top();
                st.pop();
                if(!st.empty()) pse=st.top();
                else pse=-1;
                nse=m;
                int width=(nse-pse)-1;
                area = max(area,(heights[el]*width));
            }
        }
        return area;
    }
};