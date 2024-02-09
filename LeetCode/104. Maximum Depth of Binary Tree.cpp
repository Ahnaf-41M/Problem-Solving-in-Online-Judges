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
    int call(TreeNode *cur) {
        if (cur == NULL) return 0;
        int res1 = 1 + call(cur->left);
        int res2 = 1 + call(cur->right);
        return max(res1, res2);
    }
    int maxDepth(TreeNode* root) {
        return call(root);
    }
};