/*
 * Level Order Tree Traversal
 * By Sam Firnhaber
 */

Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void levelOrderTraversal(TreeNode* node, vector<vector<int>>& values, int level) {
        
        if (values.size() == level) {
            vector<int> row;
            values.push_back(row);
        }
        values[level].push_back(node->val);
        
        if(node->left != NULL)
            levelOrderTraversal(node->left, values, level + 1);
        if(node->right != NULL)
            levelOrderTraversal(node->right, values, level + 1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> values;
        levelOrderTraversal(root, values, 0);
        return values;
    }
};