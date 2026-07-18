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
    // bool isLeaf(TreeNode* node) {
    //     return !node->left && !node->right;
    // }
    // void depth(TreeNode* node, int d, int& ans) {
    //     if(isLeaf(node)) {
    //         ans = max(ans, d);
    //         return;
    //     }
    //     if(node->left) depth(node->left, d+1, ans);
    //     if(node->right) depth(node->right, d+1, ans);
    // }
public:
    int maxDepth(TreeNode* root) {
        // if(!root) return 0;
        // int ans = 0;
        // depth(root, 1, ans);
        // return ans;
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
