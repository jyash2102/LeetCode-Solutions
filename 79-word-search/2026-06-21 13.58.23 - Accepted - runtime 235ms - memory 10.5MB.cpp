class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    bool recur(int i,int j,vector<vector<char>>& board, string& word,int idx){
        if(idx==word.length()) return true;
        int n=board.size();
        int m=board[0].size();
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='#') return false;
        if(board[i][j]!=word[idx]) return false;
        char temp=board[i][j];
        board[i][j]='#';
        for(auto [dx,dy]:dir){
            if(recur(i+dx,j+dy,board,word,idx+1)) return true;
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j] && recur(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};