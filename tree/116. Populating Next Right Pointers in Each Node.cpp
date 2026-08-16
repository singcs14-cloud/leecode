/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> v;
        preorder(root, v , 0);
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(j != v[i].size()-1){
                    v[i][j]->next = v[i][j+1];
                }
            }
            
        }


        return root;
    }
    void preorder(Node* cur , vector<vector<Node*>>& v, int level ){
        if(!cur)return;
        if(v.size() < level+1) v.push_back( vector<Node*>());
        v[level].push_back(cur);

        if(cur->left) preorder(cur->left ,v,level+1);
        if(cur->right) preorder(cur->right , v , level+1);
        
        return;
    }
};
