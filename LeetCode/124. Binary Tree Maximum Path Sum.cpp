/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = -1e5;
    int dfs(TreeNode* cur) {
        if (cur == NULL)
            return 0;
        int Left = max(0, dfs(cur->left));
        int Right = max(0, dfs(cur->right));
        int res = Left + Right + cur->val;
        ans = max(ans, res);
        return cur->val + max(Left, Right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};