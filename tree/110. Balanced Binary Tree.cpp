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
    int height(TreeNode* cur , int h){
        
        if(!cur)return h;
        h++;
        cout << cur->val <<" "<<h <<"\n";
        int ha=0,hb=0;
        ha = height(cur->left , h);
        hb = height(cur->right , h);
        cout <<"ha: "<< ha <<" hb: "<<hb <<"\n";
        return max(ha,hb);

    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        if(abs(height(root->left , 1) - height(root->right , 1)) >1  ){
            return false;
        }else{
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
    
};
