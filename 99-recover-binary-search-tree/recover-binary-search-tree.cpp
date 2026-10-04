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
    vector<TreeNode*> inorder;
    void recur(TreeNode* root){
        if(!root) return;
        recur(root->left);
        inorder.push_back(root);
        recur(root->right);
    }
    void recoverTree(TreeNode* root) {
        recur(root);
        TreeNode* a = NULL;
        TreeNode* b = NULL;
        int n = inorder.size();
        for(int i=0;i<n-1;i++){
            TreeNode* node1=inorder[i];
            TreeNode* node2=inorder[i+1];
            if(node1->val>node2->val){
                if(!a) a=node1;
                b=node2;
            }
        }
        swap(a->val,b->val);
    }
};