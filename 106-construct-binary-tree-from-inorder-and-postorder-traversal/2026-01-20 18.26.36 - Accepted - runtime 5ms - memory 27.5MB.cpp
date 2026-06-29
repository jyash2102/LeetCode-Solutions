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
    int idx;
    TreeNode* construct(int l,int r,vector<int>& postorder){
        if(l>r) return NULL;
        int rootVal=postorder[idx];
        idx--;
        TreeNode* root=new TreeNode(rootVal);
        int mid=mpp[rootVal];
        root->right=construct(mid+1,r,postorder);
        root->left=construct(l,mid-1,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        idx=n-1;
        for(int i=0;i<inorder.size();i++) {
            mpp[inorder[i]]=i;
        }
        return construct(0,inorder.size()-1,postorder);
    }
};