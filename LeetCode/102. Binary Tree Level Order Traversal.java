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
    List<Integer>[] adj = new ArrayList[2002];
    int mxLevel = -1;

    void dfs(TreeNode cur, int level) {
        if (cur == null)
            return;
        if (adj[level] == null)
            adj[level] = new ArrayList<>();
        mxLevel = Math.max(mxLevel, level);
        adj[level].add(cur.val);
        dfs(cur.left, level + 1);
        dfs(cur.right, level + 1);
    }

    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        dfs(root, 0);
        for (int i = 0; i <= mxLevel; i++) {
            List<Integer> tmp = new ArrayList<>();
            for (int x : adj[i]) {
                tmp.add(x);
            }
            ans.add(tmp);
        }
        return ans;
    }
}