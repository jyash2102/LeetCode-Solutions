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
    unordered_map<TreeNode*,TreeNode*> mpp;
    void parent(TreeNode* root){
        if(root==NULL) return;
        if(root->left!=NULL){
            mpp[root->left] = root;
            parent(root->left);
        }
        if(root->right!=NULL){
            mpp[root->right] = root;
            parent(root->right);
        }
    }
    void BFS(TreeNode* target,int k,vector<int>&ans){
        queue<TreeNode*> q;
        unordered_set<int> visited;
        if(target==NULL) return;
        q.push(target);
        visited.insert(target->val);
        while(!q.empty()){
            int size=q.size();
            if(k==0) break;
            for(int i=0;i<size;i++){
                TreeNode* el=q.front();
                q.pop();
                if(el->left!=NULL && visited.count(el->left->val)==0){
                    q.push(el->left);
                    visited.insert(el->left->val);
                }
                if(el->right!=NULL && visited.count(el->right->val)==0){
                    q.push(el->right);
                    visited.insert(el->right->val);
                }
                if(mpp.count(el)!=0 && visited.count(mpp[el]->val)==0){
                    q.push(mpp[el]);
                    visited.insert(mpp[el]->val);
                }
            }
            k--;
        }
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            ans.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        parent(root);
        BFS(target,k,ans);
        return ans;   
    }
};