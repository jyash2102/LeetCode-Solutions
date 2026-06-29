class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int max=INT_MIN;
            int idx=-1;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>max){
                    max=mat[i][mid];
                    idx=i;
                } 
            }
            int left,right;
            if(mid-1>=0) left=mat[idx][mid-1];
            else left=-1;
            if(mid+1<m) right=mat[idx][mid+1];
            else right=-1;
            if(max>left && max>right) return {idx,mid};
            else if(max<left) high=mid-1;
            else low=mid+1;
        }
        return{-1,-1};
    }
};