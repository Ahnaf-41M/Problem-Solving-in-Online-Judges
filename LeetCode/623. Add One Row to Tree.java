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
    private TreeNode dfs(TreeNode root, int val, int curDepth) {
        if (root == null)
            return null;
        if (curDepth == 1) {
            TreeNode tmpLeft = new TreeNode(val);
            TreeNode tmpRight = new TreeNode(val);
            tmpLeft.left = root.left;
            tmpRight.right = root.right;
            root.left = tmpLeft;
            root.right = tmpRight;

            return root;
        }
        root.left = dfs(root.left, val, curDepth - 1);
        root.right = dfs(root.right, val, curDepth - 1);
        return root;
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }

        return dfs(root, val, depth - 1);
    }
}