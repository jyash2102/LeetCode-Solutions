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
    void preorder(TreeNode* root,queue<int>& q){
        if(root==NULL){
            return;
        }
        q.push(root->val);
        preorder(root->left,q);
        preorder(root->right,q);
    }
    void create(TreeNode* root,queue<int>& q){
        if(q.empty()) return;
        int el=q.front();
        q.pop();
        TreeNode* temp= new TreeNode(el);
        root->right=temp;
        create(root->right,q);
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        queue<int> q;
        preorder(root,q); 
        root->left=NULL;
        root->right=NULL;
        q.pop();
        create(root,q);
    }
};