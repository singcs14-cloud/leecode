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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> anss;
        preorder(ans , root , 0);
        for(int i=0; i<ans.size();i++){
            int n = ans[i].size()-1;
            anss.push_back(ans[i][n]);
        }
        return anss;
    }
     void preorder(vector<vector<int>>& ans , TreeNode* cur, int level){
        if(!cur)return;
        if(ans.size() < level+1) ans.push_back(vector<int>());
        
        ans[level].push_back(cur->val);
        if(cur->left) preorder(ans , cur->left, level+1);
        if(cur->right) preorder(ans , cur->right, level+1);
        return;
    }
};
