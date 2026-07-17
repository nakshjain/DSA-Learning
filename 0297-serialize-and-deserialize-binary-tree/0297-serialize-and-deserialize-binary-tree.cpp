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

    string token(const string& data, int& i){
        int start=i;
        while(data[i]!='_') i++;
        string num = data.substr(start, i-start);
        i++;
        return num;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans;
        string nullString = "N_";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(!front) ans+=nullString;
            else{
                ans=ans+to_string(front->val)+"_";
                q.push(front->left);
                q.push(front->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string nullString = "N";
        if(data.size()==0 || data==nullString) return nullptr;
        int i=0;
        TreeNode* root = new TreeNode(stoi(token(data, i)));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            string left = token(data, i);
            if(left!=nullString){
                front->left = new TreeNode(stoi(left));
                q.push(front->left);
            }
            string right =token(data, i);
            if(right!=nullString){
                front->right = new TreeNode(stoi(right));
                q.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));