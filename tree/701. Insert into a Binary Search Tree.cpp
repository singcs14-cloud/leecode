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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* child = new TreeNode(val);
        if(!root) return child;
        TreeNode* parent = find(root , val);
        
        if(parent->val > val)parent->left = child;
        else parent->right = child;
        return root;
    }
    TreeNode* find(TreeNode* cur , int val){
        
        if(cur->val <val){
            if(cur->right)return find(cur->right , val);
            else return cur;

        }
        if(cur->val >val ){
            if(cur->left) return find(cur->left , val);
            else return cur;
        }
        return NULL;
        
    }
};
