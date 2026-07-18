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
    bool check(TreeNode* node, int lb, int rb) {
        if(!node) return true;
        if(node->val <= lb || node->val >= rb) return false;
        return check(node->left, lb, node->val) && check(node->right, node->val, rb);
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, INT_MIN, INT_MAX);
    }
};
