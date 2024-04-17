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
    private void dfs(TreeNode root, StringBuilder cur, StringBuilder ans) {
        if (root == null)
            return;

        cur.append((char)('a' + root.val));
        if (root.left == null && root.right == null) {
            cur.reverse();
            if (ans.length() == 0 || cur.compareTo(ans) < 0) {
                ans.setLength(0);
                ans.append(cur);
            }
            cur.reverse();
        }

        dfs(root.left, cur, ans);
        dfs(root.right, cur, ans);
        cur.setLength(cur.length() - 1);
    }

    public String smallestFromLeaf(TreeNode root) {
        StringBuilder ans = new StringBuilder();
        dfs(root, new StringBuilder(), ans);
        return ans.toString();
    }
}