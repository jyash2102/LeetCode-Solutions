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
    int ans=0;
    void recur(TreeNode* root,int maxi){
        if(root==NULL)  return;
        maxi=max(root->val,maxi);
        if(maxi==root->val) ans++;
        recur(root->left,maxi);
        // maxi=max(maxi,root->val);
        recur(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        recur(root,INT_MIN);
        return ans;
    }
};