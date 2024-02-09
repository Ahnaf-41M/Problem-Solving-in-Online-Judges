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
    void call(TreeNode *cur) {
        if (cur == NULL) return;
        call(cur->left);
        call(cur->right);

        TreeNode *tmp = cur->left;
        cur->left = cur->right;
        cur->right = tmp;
    }
    TreeNode* invertTree(TreeNode* root) {
        call(root);
        return root;
    }
};