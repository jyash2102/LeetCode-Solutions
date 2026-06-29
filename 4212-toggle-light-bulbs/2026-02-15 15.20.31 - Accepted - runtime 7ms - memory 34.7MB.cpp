class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> ans;
        int n = bulbs.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[bulbs[i]]++;
        }
        for(auto& it: mpp){
            if(it.second%2==1) ans.push_back(it.first);
        }
        return ans;
    }
    
};