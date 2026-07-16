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
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) map[inorder[i]]=i;
        return helper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }

    //preorder = [pl, ph)
    //inorder = [il, ih)
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pl, int ph, int il, int ih) {
        if(!(ph-pl) || !(ih-il)) return nullptr;
        TreeNode* root = new TreeNode(preorder[pl]);
        int inorderIndex = map[preorder[pl]]; //1
        int leftSize = inorderIndex - il;
        root->left = helper(preorder, inorder, pl+1, pl+1+leftSize, il, il+leftSize);
        root->right = helper(preorder, inorder, pl+1+leftSize, ph, inorderIndex+1, ih);
        return root;
    }

};