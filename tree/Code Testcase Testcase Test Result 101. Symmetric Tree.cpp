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
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        
        if(root->left && root->right){
            return symmetric(root->left, root->right);
        }else if(!root->left && !root->right){
            return true;
        }else return false;
  
    }
    bool symmetric(TreeNode* leftt , TreeNode* rightt){
        
        if(leftt->val != rightt->val){
            return false;
        }
        bool test1 =false,test2 = false;
        if(leftt->left && rightt->right) test1 = symmetric(leftt->left , rightt->right);
        else if(!leftt->left && !rightt->right){
            test1 = true;
        }
        if(leftt->right && rightt->left) test2 = symmetric(leftt->right , rightt->left);
        else if(!leftt->right && !rightt->left){
            test2 = true;
        }
        return test1 && test2;
    }
};
