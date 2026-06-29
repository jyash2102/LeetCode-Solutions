class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int>> ans;
        for(auto v: occupiedIntervals){
            if(ans.empty()){
                ans.push_back(v);
                continue;
            }
            int s1=ans.back()[0];
            int e1=ans.back()[1];
            int s2=v[0];
            int e2=v[1];
            if(e1+1>=s2) ans.back()[1]=max(e1,e2);
            else ans.push_back(v);
        }
        vector<vector<int>> ans1;
        for(auto& v : ans){
            int fs=v[0];
            int fe=v[1];
            if(fe < freeStart || fs > freeEnd) {
                ans1.push_back(v);
            }
            else if(freeStart<=fs && freeEnd>=fe) continue;
            else if(freeStart>fs && freeEnd<fe){
                ans1.push_back({fs,freeStart-1});
                ans1.push_back({freeEnd+1,fe});
            }
            else if(freeStart > fs && freeStart <= fe) {
                ans1.push_back({fs, freeStart - 1});
            }
            else if(freeEnd >= fs && freeEnd < fe) {
                ans1.push_back({freeEnd + 1, fe});
            }
        }
        return ans1;
    }
};