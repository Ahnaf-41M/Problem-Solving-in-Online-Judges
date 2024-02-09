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
    int ans = 0;
    int dfs(TreeNode* cur) {
        if (cur == NULL)
            return 0;
        int Left = 1 + dfs(cur->left);
        int Right = 1 + dfs(cur->right);

        int curDiameter = Left + Right - 2;
        ans = max(ans, curDiameter);
        return max(Left, Right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};