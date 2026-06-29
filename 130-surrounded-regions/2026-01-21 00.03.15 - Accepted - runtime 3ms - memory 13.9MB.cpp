class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    bool flag=false;
    void DFS(int i,int j,vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!='O') return;
        board[i][j]='#';
        for(auto& [dx,dy] : dir){
            int row=i+dx;
            int col=j+dy;
            DFS(row,col,board);
        } 
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            DFS(i,0,board);
            DFS(i,n-1,board);
        }
        for(int i=0;i<n;i++){
            DFS(0,i,board);
            DFS(m-1,i,board);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#') board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};