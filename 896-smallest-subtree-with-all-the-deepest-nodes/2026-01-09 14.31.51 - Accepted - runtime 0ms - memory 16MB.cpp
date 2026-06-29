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
    int depth(TreeNode* node){
        if(node==NULL) return 0;
        int lh=depth(node->left);
        int rh=depth(node->right);
        return 1+max(lh,rh);
    }
    TreeNode* deepest(TreeNode* root,int depth){
        if(root==NULL) return NULL;
        if(depth==0) return root;
        TreeNode* left=deepest(root->left,depth-1);
        TreeNode* right=deepest(root->right,depth-1);
        if(left!=NULL && right!=NULL) return root;
        return left ? left : right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return deepest(root,depth(root)-1);
    }
};