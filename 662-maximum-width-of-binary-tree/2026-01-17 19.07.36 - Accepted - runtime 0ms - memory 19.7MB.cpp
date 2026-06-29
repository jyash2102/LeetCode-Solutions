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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        if(root==NULL) return 0;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            int size=q.size();
            long long first = q.front().second;
            long long last = q.back().second;
            ans = max(ans, last - first + 1);
            for(int i=0;i<size;i++){
                auto el=q.front();
                q.pop();
                TreeNode* node=el.first;
                long long idx=el.second-first;
                if(node->left!=NULL){
                    q.push({node->left,2*idx+1});
                }
                if(node->right!=NULL){
                    q.push({node->right,2*idx+2});
                }
            } 
        }
        return ans;
    }
};