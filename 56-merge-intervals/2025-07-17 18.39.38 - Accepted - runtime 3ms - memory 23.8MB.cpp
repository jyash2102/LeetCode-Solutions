class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int s1=intervals[i][0],e1=intervals[i][1];
            if (!ans.empty() && e1 <= ans.back()[1]) {
                continue;
            }

            for(int j=i+1;j<n;j++){
                int s2=intervals[j][0],e2=intervals[j][1];
                if(e1>=s2){
                    e1=max(e1,e2);
                }
                else break;
            }
            ans.push_back({s1,e1});
        }
        return ans;
    }
};