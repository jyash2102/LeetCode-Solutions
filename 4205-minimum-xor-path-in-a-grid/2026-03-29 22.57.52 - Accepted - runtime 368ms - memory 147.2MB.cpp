class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{0,1}};
    int mini = INT_MAX;
    vector<vector<array<bool,1024>>> dp;

    void recur(vector<vector<int>>& grid, int i, int j, int XOR) {
        int n = grid.size();
        int m = grid[0].size();
        if (i<0 || j<0 || i>=n || j>=m) return;
        if (dp[i][j][XOR]) return;
        dp[i][j][XOR] = true;

        if (i==n-1 && j==m-1) {
            mini = min(mini, XOR);
            return;
        }
        for (auto& [dx,dy]: dir) {
            int ni = i+dx, nj = j+dy;
            if (ni<0||nj<0||ni>=n||nj>=m) continue;
            recur(grid, ni, nj, XOR ^ grid[ni][nj]);
        }
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int molqaviren = grid[0][0]; 
        dp.assign(n, vector<array<bool,1024>>(m, array<bool,1024>{}));
        recur(grid, 0, 0, molqaviren);
        return mini;
    }
};