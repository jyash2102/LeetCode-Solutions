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
    // int ans=-1;
    // void inorder(TreeNode* root,int& k){
    //     if(root==NULL) return;
    //     inorder(root->left,k);
    //     k--;
    //     if(k==0){
    //         ans=root->val;
    //         return;
    //     }
    //     inorder(root->right,k);
    // }
    int kthSmallest(TreeNode* root, int& k) {
        if (root == NULL) return -1; // sentinel: not found in this subtree

        int left = kthSmallest(root->left, k);
        if (left != -1) return left; // already found on the left, bubble it up

        k--;
        if (k == 0) return root->val; // this node is the answer

        return kthSmallest(root->right, k);
    }
};