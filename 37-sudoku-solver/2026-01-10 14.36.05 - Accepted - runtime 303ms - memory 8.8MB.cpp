class Solution {
public:
    bool valid(char n,int row,int col,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[row][i]==n) return false;
            if(board[i][col]==n) return false;
        }
        int roww=(row/3)*3;
        int coll=(col/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[roww+i][coll+j]==n) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char d='1';d<='9';d++){
                        if(valid(d,i,j,board)){
                            board[i][j]=d;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};