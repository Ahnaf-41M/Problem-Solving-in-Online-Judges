/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    TreeNode dfs(TreeNode cur, int target) {
        if (cur == null)
            return cur;
        cur.left = dfs(cur.left, target);
        cur.right = dfs(cur.right, target);
        if (cur.left == null && cur.right == null && cur.val == target) {
            cur = null;
        }
        return cur;
    }

    public TreeNode removeLeafNodes(TreeNode root, int target) {
        root.left = dfs(root.left, target);
        root.right = dfs(root.right, target);
        if (root.left == null && root.right == null && root.val == target) {
            root = null;
        }
        return root;
    }
}