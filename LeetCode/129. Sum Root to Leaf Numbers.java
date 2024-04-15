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
    private int ans = 0;

    private void traverse(TreeNode cur, int num) {
        if (cur.left == null && cur.right == null) {
            ans += (num * 10 + cur.val);
            return;
        } else if (cur.left == null) {
            traverse(cur.right, num * 10 + cur.val);
        } else if (cur.right == null) {
            traverse(cur.left, num * 10 + cur.val);
        } else {
            traverse(cur.left, num * 10 + cur.val);
            traverse(cur.right, num * 10 + cur.val);
        }
    }
    public int sumNumbers(TreeNode root) {
        traverse(root, 0);
        return ans;
    }
}