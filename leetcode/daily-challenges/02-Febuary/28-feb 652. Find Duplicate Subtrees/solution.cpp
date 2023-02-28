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
    unordered_map<string, int> subtrees;
    vector<TreeNode*> duplicates; 
    string serializeSubtrees(TreeNode* node) {
        if (!node) return "#";
        
        string left = serializeSubtrees(node->left);
        string right = serializeSubtrees(node->right);
        
        string s = to_string(node->val)+"("+left + ")(" + right + ")" ;
        
        if (subtrees[s] == 1) 
            duplicates.push_back(node);
        
        subtrees[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
         // Traverse the tree and serialize subtrees
        serializeSubtrees(root);        
        return duplicates;
    }
};