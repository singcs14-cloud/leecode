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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0)return NULL;

        int value = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(value);
        if(postorder.size() == 1)return root;

        int pos=0;
        for(pos = 0;pos<inorder.size(); pos++){
            if(inorder[pos] == value) break;
        }
        //左閉又開
        vector<int> leftinorder(inorder.begin() , inorder.begin()+pos);
        vector<int> rightinorder(inorder.begin()+pos+1 , inorder.end());

        postorder.resize(postorder.size()-1);

        vector<int> leftpostorder(postorder.begin() , postorder.begin()+leftinorder.size());
        vector<int> rightpostorder(postorder.begin()+leftinorder.size() , postorder.end());

        root->left = buildTree(leftinorder,  leftpostorder);
        root->right = buildTree(rightinorder,  rightpostorder); 
        return root;

    }
};
