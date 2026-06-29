class Solution {
public:
    void recur(int idx,int n,vector<vector<string>>& ans,vector<string>& v,vector<int> colwise,vector<int>& rightdiag,vector<int>& leftdiag){
        if(idx==n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(colwise[i]==0 && rightdiag[idx+i]==0 && leftdiag[(n-1)+(idx-i)]==0){
                v[idx][i]='Q';
                colwise[i]=1;
                rightdiag[idx+i]=1;
                leftdiag[(n-1)+(idx-i)]=1;
                recur(idx+1,n,ans,v,colwise,rightdiag,leftdiag);
                v[idx][i]='.';
                colwise[i]=0;
                rightdiag[idx+i]=0;
                leftdiag[(n-1)+(idx-i)]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n,string(n,'.'));
        vector<int> colwise(n,0);
        vector<int> rightdiag(2*n-1,0);
        vector<int> leftdiag(2*n-1,0);
        recur(0,n,ans,v,colwise,rightdiag,leftdiag);
        return ans;
    }
};