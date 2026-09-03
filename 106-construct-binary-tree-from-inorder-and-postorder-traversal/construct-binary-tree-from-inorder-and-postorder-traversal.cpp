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
    unordered_map<int,int> mpp;
    int idx;
    TreeNode* construct(int l,int r, vector<int>& postorder){
        if(l>r) return NULL;
        int rootval=postorder[idx];
        idx--;
        TreeNode* root= new TreeNode(rootval);
        int mid=mpp[rootval];
        root->right=construct(mid+1,r,postorder);
        root->left=construct(l,mid-1,postorder);
        return root;        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx=postorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return construct(0,inorder.size()-1,postorder);
    }
};