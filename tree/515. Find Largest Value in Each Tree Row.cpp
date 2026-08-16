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
    vector<int> largestValues(TreeNode* root) {
        vector<int> vv;
        int maxlevel=0;
        leveltraversal(root, vv , 0 , maxlevel);
        return vv;
    }
    void leveltraversal(TreeNode* cur , vector<int>& vv , int level , int& maxlevel){
        if(!cur)return;
        int n = cur->val;
        maxlevel = max(level , maxlevel);

        if(vv.size() < level+1){
            vv.push_back(n);
        }else{
            vv[level] = max( vv[level] , n);
        }
        if(cur->left) leveltraversal(cur->left , vv , level+1 , maxlevel);
        if(cur->right) leveltraversal(cur->right , vv , level+1 , maxlevel);
        return;

    }
};
