class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        for (auto &row : guards) {
            int x = row[0];
            int y = row[1];
            grid[x][y]=1;
        }
        for (auto &row : walls) {
            int x = row[0];
            int y = row[1];
            grid[x][y]=2;
        }
        vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        for (auto &row : guards) {
            int x = row[0];
            int y = row[1];
            for (auto &[dx,dy]:directions) {
                int i= x + dx, j = y + dy;
                while (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != 1 && grid[i][j] != 2) {
                    if(grid[i][j] == 0) grid[i][j] = 3; 
                    i+=dx;
                    j+=dy;
                }
            }
        }
        int count=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==0) count++;
                }
            }
        return count;
    }
};