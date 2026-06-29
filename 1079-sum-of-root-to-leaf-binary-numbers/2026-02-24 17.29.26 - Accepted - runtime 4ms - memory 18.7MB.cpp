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
    void BFS(TreeNode* root,string& s,int& ans){
        if(root==NULL){
            return;
        }
        s+=to_string(root->val);
        if(root->left==NULL & root->right==NULL){
            ans+=stoi(s,nullptr,2);
        }
        BFS(root->left,s,ans);
        BFS(root->right,s,ans);
        s.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        string s="";
        BFS(root,s,ans);
        return ans;
    }
};