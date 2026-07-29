/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recur(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==p || root==q) return root;
        if(root==NULL) return NULL;
        TreeNode* left=recur(root->left,p,q);
        TreeNode* right=recur(root->right,p,q);
        if(left!=NULL && right!=NULL) return root;
        if(left!=NULL && right==NULL) return left;
        if(left==NULL && right!=NULL) return right;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {  
        return recur(root,p,q);
    }
};