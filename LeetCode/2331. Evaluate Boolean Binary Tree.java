/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    boolean dfs(TreeNode cur) {
        if (cur.val <= 1) return cur.val == 1;
        if (cur.val == 2) {
            return dfs(cur.left) | dfs(cur.right);
        } else {
            return dfs(cur.left) & dfs(cur.right);
        }
    }
    public boolean evaluateTree(TreeNode root) {
        return dfs(root);
    }
}