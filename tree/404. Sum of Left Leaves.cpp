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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        traversal(root , sum , false);
        return sum;
        
    }
    void traversal(TreeNode* cur , int& sum, bool left){
        if(!cur->left && !cur->right && left){
            cout<< cur->val <<"\n";
            sum += cur->val;
        }
        if(cur->left) traversal(cur->left , sum , true);
        if(cur->right) traversal(cur->right , sum , false);
        return;
    }
};
