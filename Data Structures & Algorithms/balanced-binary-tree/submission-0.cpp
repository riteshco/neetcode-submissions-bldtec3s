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
    int f(TreeNode* node, bool& ans) {
        if(!node) return 0;
        int left = f(node->left, ans);
        int right = f(node->right, ans);
        if(abs(left-right) > 1) ans = false;
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        f(root, ans);
        return ans;
    }
};
