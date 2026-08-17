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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)return NULL;

        int max=0;int pos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > max){
                max = nums[i];
                pos = i;
            }
        }

        TreeNode* root = new TreeNode(max);
        if(nums.size() == 1)return root;

        vector<int> left(nums.begin() , nums.begin()+pos);
        vector<int> right(nums.begin()+pos+1 , nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;

    }
    
};
