/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void ser(TreeNode* root,string& s){
        if(root==NULL){
            s.append("#,");
            return;
        }
        s.append(to_string(root->val)+",");
        ser(root->left,s);
        ser(root->right,s);
    }
    string serialize(TreeNode* root) {
        string s;
        ser(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deser(queue<string>& q){
        string t=q.front();
        q.pop();
        if(t=="#") return NULL;
        TreeNode* root = new TreeNode(stoi(t));
        root->left=deser(q);
        root->right=deser(q);
        return root;
    }
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp;
        for(char c : data){
            if(c==','){
                q.push(temp);
                temp.clear();
            }
            else temp+=c;
        }
        return deser(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));