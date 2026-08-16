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
    TreeNode* invertTree(TreeNode* root) {
        preorder(root);
        return root;
    }
    void preorder(TreeNode* cur){
        if(!cur) return ;
        if(cur->left || cur->right){
            swap(cur->left , cur->right);
     
        }
        if(cur->left) preorder(cur->left);
        if(cur->right) preorder(cur->right);
        return;
    }
};
