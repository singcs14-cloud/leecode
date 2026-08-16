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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* l = root;
        TreeNode* r = root;
        int ldep=0 , rdep=0;
        while(l){
            ldep++;
            l = l->left;
        }
        while(r){
            rdep++;
            r = r->right;
        }
        if(ldep == rdep) return pow(2,ldep)-1;
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
       
       
    }
    
};
