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
    void in(vector<int>& inorder,TreeNode* root){
        if(root==NULL) return;
        in(inorder,root->left);
        inorder.push_back(root->val);
        in(inorder,root->right);
    }
    TreeNode* convert(vector<int>& inorder,int low,int high){
        if(low>high) return NULL;
        int mid=low+(high-low)/2;
        TreeNode* node=new TreeNode(inorder[mid]);
        node->left=convert(inorder,low,mid-1);
        node->right=convert(inorder,mid+1,high);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        in(inorder,root);
        return convert(inorder,0,inorder.size()-1);
    }
};