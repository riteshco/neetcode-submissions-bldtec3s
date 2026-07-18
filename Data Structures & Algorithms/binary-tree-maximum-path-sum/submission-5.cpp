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
        int left = f(node->left, ans);
        int right = f(node->right, ans);
        int maxi = node->val + max(left, right);
        maxi = max(maxi, node->val);
        ans = max(ans, max(maxi, node->val + left + right));
        return maxi;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        f(root, ans);
        return ans;
    }
};
