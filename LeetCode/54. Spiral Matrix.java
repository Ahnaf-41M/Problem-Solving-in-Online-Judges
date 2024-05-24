class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int n = matrix.length, m = matrix[0].length;
        boolean[][] vis = new boolean[n][m];
        int i = 0, j = -1, len = 0;

        while (len < n * m) {
            while (j + 1 < m && !vis[i][j + 1]) {
                ans.add(matrix[i][j + 1]);
                len++;
                vis[i][j + 1] = true;
                j++;
            }
            while (i + 1 < n && !vis[i + 1][j]) {
                ans.add(matrix[i + 1][j]);
                len++;
                vis[i + 1][j] = true;
                i++;
            }
            while (j - 1 >= 0 && !vis[i][j - 1]) {
                ans.add(matrix[i][j - 1]);
                len++;
                vis[i][j - 1] = true;
                j--;
            }
            while (i - 1 >= 0 && !vis[i - 1][j]) {
                ans.add(matrix[i - 1][j]);
                len++;
                vis[i - 1][j] = true;
                i--;
            }
        }
        return ans;
    }
}