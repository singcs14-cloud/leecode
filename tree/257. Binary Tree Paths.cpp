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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root)return result;
        vector<int> path;
        traversal(root , path , result);
        return result;
    }
    void traversal(TreeNode* cur , vector<int> path , vector<string>& result){
        path.push_back(cur->val);
        if( !cur->left && !cur->right){
            cout << cur->val <<"\n";
            string s;
            for(int i=0;i<path.size();i++){
                if(i != 0) s+="->";
                s += to_string(path[i]);
            }
            result.push_back(s);
        }
        
        if(cur->left)traversal(cur->left , path , result);
        if(cur->right)traversal(cur->right , path , result);
        
        return;

    }
};
