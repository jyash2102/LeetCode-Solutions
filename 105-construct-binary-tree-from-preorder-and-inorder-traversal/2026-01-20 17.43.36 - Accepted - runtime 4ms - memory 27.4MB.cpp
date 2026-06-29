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
    unordered_map<int,int> mpp;//inorder index
    int idx=0;
    TreeNode* construct(int l,int r,vector<int>& preorder){
        if(l>r) return NULL;
        int rootval=preorder[idx];
        idx++;
        TreeNode* root= new TreeNode(rootval);
        int mid=mpp[rootval];
        root->left=construct(l,mid-1,preorder);
        root->right=construct(mid+1,r,preorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) {
            mpp[inorder[i]]=i;
        }

        return construct(0,inorder.size() - 1,preorder);
    }
};