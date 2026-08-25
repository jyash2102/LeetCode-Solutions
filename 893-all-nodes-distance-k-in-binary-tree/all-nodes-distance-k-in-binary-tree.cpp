/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void recur(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mpp){
        if(root==NULL) return;
        if(root->left!=NULL) mpp[root->left]=root;
        if(root->right!=NULL) mpp[root->right]=root;
        recur(root->left,mpp);
        recur(root->right,mpp);
    }
    void bfs(TreeNode* target, int k,unordered_map<TreeNode*,TreeNode*>& mpp,
    unordered_map<TreeNode*,bool>& vis){
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* el=q.front();
                q.pop();
                if(el->left!=NULL && !vis[el->left]) q.push(el->left);
                if(el->right!=NULL && !vis[el->right]) q.push(el->right);
                if(mpp.find(el)!=mpp.end() && !vis[mpp[el]]) q.push(mpp[el]);
                if(k==0) ans.push_back(el->val);
                vis[el->left]=true;
                vis[el->right]=true;
                vis[mpp[el]]=true;
            }
            k--;
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mpp;
        unordered_map<TreeNode*,bool> vis;
        recur(root,mpp);
        bfs(target,k,mpp,vis);
        return ans;
    }
};