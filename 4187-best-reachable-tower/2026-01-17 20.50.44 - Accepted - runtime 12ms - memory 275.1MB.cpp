class Solution {
public:
    int distance(int i,int j,int c1,int c2){
        return abs(i-c1) + abs(j-c2);
    }

    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> ans = {-1, -1};
        int q = -1;

        for(auto& it : towers){
            int d = distance(it[0], it[1], center[0], center[1]);

            if(d <= radius){
                if(it[2] > q ||
                   (it[2] == q && 
                    (ans[0] == -1 || 
                     make_pair(it[0], it[1]) < make_pair(ans[0], ans[1])))) {

                    q = it[2];
                    ans[0] = it[0];
                    ans[1] = it[1];
                }
            }
        }
        return ans;
    }
};
