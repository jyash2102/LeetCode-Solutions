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
    bool flag=true;
    int depth(TreeNode* node){
        if(node==NULL) return 0;
        int lh=depth(node->left);
        int rh=depth(node->right);
        if(abs((lh-rh))>1) flag=false;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        int dep=depth(root);
        return flag;
    }
};