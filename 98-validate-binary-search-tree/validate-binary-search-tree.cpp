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
#define ll long long
public:
    bool recur(TreeNode* root,ll low,ll high){
        if(!root) return true;
        if(root->val<=low || root->val>=high) return false;
        bool left=recur(root->left,low,min(high,(ll)root->val));
        if(!left) return false;
        bool right=recur(root->right,max((ll)root->val,low),high);
        if(!right) return false;
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return recur(root,LLONG_MIN,LLONG_MAX);
    }
};