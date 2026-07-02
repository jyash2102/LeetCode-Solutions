class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    bool recur(int row,int col,vector<vector<int>>& grid,int health, vector<vector<int>>& best){
        int n = grid.size();
        int m = grid[0].size();
        if(health<1) return false;
        if(row==n-1 && col==m-1) return true; 
        if(health <= best[row][col]) return false;
        best[row][col] = health;
        for(auto& [dx,dy] : dir){
            int nr=row+dx;
            int nc=col+dy;
            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
            int newhealth = health - grid[nr][nc];
            if(recur(nr,nc,grid,newhealth,best)) return true;
        }
        return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1) health--;
        vector<vector<int>> best(n,vector<int>(m,0));
        return recur(0,0,grid,health,best);
    }
};