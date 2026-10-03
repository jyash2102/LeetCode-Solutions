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
    stack<TreeNode*> st1,st2;
    void pushleft(TreeNode* root){
        if(!root) return ;
        while(root){
            st1.push(root);
            root=root->left;
        }
    }
    void pushright(TreeNode* root){
        if(!root) return ;
        while(root){
            st2.push(root);
            root=root->right;
        }
    }
    bool solve(TreeNode* root, int k){
        if(!root) return false;
        if(st1.empty() || st2.empty()) return false;
        int val1=st1.top()->val; 
        int val2=st2.top()->val; 
        if(val1>=val2) return false;
        if(val1+val2>k){
            TreeNode* node = st2.top(); st2.pop();
            pushright(node->left);
            return solve(root,k);
        }
        else if(val1+val2<k){
            TreeNode* node = st1.top(); st1.pop();
            pushleft(node->right);
            return solve(root,k);
        }
        return true;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        pushleft(root);
        pushright(root);
        return solve(root,k);
    }
};