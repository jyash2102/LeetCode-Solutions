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
    stack<TreeNode*> st;
    TreeNode* prev=NULL;
    TreeNode* curr=NULL;
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    void pushleft(TreeNode* root){
        if(!root) return;
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    void recur(TreeNode* root){
        if(!root) return;
        pushleft(root);
        while(!st.empty()){
            curr=st.top();st.pop();
        pushleft(curr->right);
        if(prev && curr){
            if(prev->val>curr->val){
                if(!first) first=prev;
                second=curr;
            }
        }
        prev=curr;
        }
    }
    void recoverTree(TreeNode* root) {
        recur(root);
        swap(first->val,second->val);
    }
};