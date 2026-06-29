class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted=arr;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int> mpp;
        int rank=1;
        for(int i=0;i<n;i++){
            if(mpp.find(sorted[i])==mpp.end()){
                mpp[sorted[i]]=rank;
                rank++;
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=mpp[arr[i]];
        }
        return ans;   
    }
};