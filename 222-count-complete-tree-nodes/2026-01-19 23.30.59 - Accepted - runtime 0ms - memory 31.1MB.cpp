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
    //o((logn)^2) approach
    int lefth(TreeNode* root){
        if(root==NULL) return 0;
        return 1+lefth(root->left);
    }
    int righth(TreeNode* root){
        if(root==NULL) return 0;
        return 1+righth(root->right);
    }
    int count(TreeNode* root){
        if(root==NULL) return 0;
        int lh=lefth(root);
        int rh=righth(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+count(root->left)+count(root->right);
    }
    int countNodes(TreeNode* root) {
        return count(root);
    }
};