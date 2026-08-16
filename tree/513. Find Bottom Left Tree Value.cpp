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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> v;
        preorder(root , v , 0);
        return v[v.size()-1];
    }
    void preorder(TreeNode* cur , vector<int>& v , int level ){
        if(!cur)return;
        if(v.size() < level+1)v.push_back(cur->val);
        preorder(cur->left , v , level+1 );
        preorder(cur->right , v , level+1 );
        return;
    }
};
