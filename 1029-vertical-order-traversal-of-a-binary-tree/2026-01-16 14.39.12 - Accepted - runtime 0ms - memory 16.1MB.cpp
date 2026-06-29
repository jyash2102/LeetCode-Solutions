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
    map<int,vector<pair<int,int>>> mpp;
    void traverse(TreeNode* root,int i,int j){
        if(root==NULL) return;
        mpp[j].push_back({i,root->val});
        traverse(root->left,i+1,j-1);
        traverse(root->right,i+1,j+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root,0,0);
        vector<vector<int>> ans;
        for(auto& it: mpp){
            auto& vec=it.second;
            sort(vec.begin(),vec.end());
            vector<int> v;
            for (auto &p : vec) {
                v.push_back(p.second);
            }
            ans.push_back(v);
        }
        return ans;
    }
};