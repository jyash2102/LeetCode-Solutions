/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recur(TreeNode* root,int row,int col,map<int,map<int,multiset<int>>>& mpp){
        if(root==NULL) return;
        mpp[col][row].insert(root->val);
        recur(root->left,row+1,col-1,mpp);
        recur(root->right,row+1,col+1,mpp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp;
        recur(root,0,0,mpp);
        vector<vector<int>> ans;
        for(auto it1 : mpp){
            vector<int> v;
            for(auto it2 : it1.second){
                for(auto x : it2.second){
                    v.push_back(x);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};