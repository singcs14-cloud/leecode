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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;

        unordered_map<int , int> fre;
        int maxfre=0;
        int maxval=0;
        preorder(root , maxfre , fre , maxval);
        for(auto i = fre.begin() ; i != fre.end(); i++){
            if(i->second == maxfre) ans.push_back(i->first);
        }
        return ans;
    }
    void preorder(TreeNode* cur , int& maxfre , unordered_map<int , int>& fre , int& maxval){
        if(!cur) return;
        fre[cur->val]++;
        maxfre = max (fre[cur->val] , maxfre );
        maxval = max( maxval , cur->val);
        preorder(cur->left, maxfre , fre, maxval);
        preorder(cur->right , maxfre , fre , maxval);
        return;
    }
};
