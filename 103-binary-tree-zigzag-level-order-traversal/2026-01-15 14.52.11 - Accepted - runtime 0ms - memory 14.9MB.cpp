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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        q.push(root);
        int a=0;
        while(!q.empty()){
            vector<int> v;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* el=q.front();
                q.pop();
                if(el->left!=NULL) q.push(el->left);
                if(el->right!=NULL) q.push(el->right);
                v.push_back(el->val);
            }
            if(a%2!=0){
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            else ans.push_back(v);
            a++;
        }
        return ans;
    }
};