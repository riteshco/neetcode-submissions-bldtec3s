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
    int f(TreeNode* node, int& ans) {
        if(!node) return 0;
        int left = max(0, f(node->left, ans));
        int right = max(0, f(node->right, ans));
        ans = max(ans, node->val + left + right);
        return node->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        f(root, ans);
        return ans;
    }
};
