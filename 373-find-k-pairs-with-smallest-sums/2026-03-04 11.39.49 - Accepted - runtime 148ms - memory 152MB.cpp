class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>  pq;
        set<pair<int,int>> st;
        pq.push({nums1[0]+nums2[0],0,0});
        st.insert({0,0});
        vector<vector<int>> ans;
        while(k-- && !pq.empty()){
            auto top=pq.top();
            pq.pop();
            int i=top[1];
            int j=top[2];
            ans.push_back({nums1[i],nums2[j]});
            if(i+1<n && !st.count({i+1,j})){
                pq.push({nums1[i+1]+nums2[j],i+1,j});
                st.insert({i+1,j});
            }
            if(j+1<m && !st.count({i,j+1})){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
                st.insert({i,j+1});
            }
        }
        return ans;
    }
};