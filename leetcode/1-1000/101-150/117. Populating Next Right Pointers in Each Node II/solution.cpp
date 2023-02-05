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
    Node* leftMost(Node* root){
        if(!root)
            return root;
        if(root->left)
            return root->left;
        if(root->right)
            return root->right;

        return leftMost(root->next);
        
    }
    
    Node* nextRight(Node* root){
        if(root->right)
            return root->right;
        return leftMost(root->next);
    }
    
    Node* connect(Node* root) {
        if(!root)
            return root;
        
        if(root->right){
            root->right->next = leftMost(root->next);
        }
        
        if(root->left){
            root->left->next = nextRight(root);
        }
        
        root->right = connect(root->right);
        root->left = connect(root->left);
        
        return root;
    }
    
    
};