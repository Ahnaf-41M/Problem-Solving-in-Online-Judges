class Solution {
    int n, m, len;
    boolean[][] vis = new boolean[6][6];

    boolean valid(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
    }

    boolean backtrack(int x, int y, char[][] board, int i, String word) {
        if (i == len - 1) {
            return true;
        }
        if (!valid(x, y)) {
            return false;
        }
        vis[x][y] = true;
        boolean ans = false;
        if (i + 1 < len && board[x][y] == word.charAt(i + 1)) {
            ans = ans | backtrack(x + 1, y, board, i + 1, word);
            ans = ans | backtrack(x - 1, y, board, i + 1, word);
            ans = ans | backtrack(x, y + 1, board, i + 1, word);
            ans = ans | backtrack(x, y - 1, board, i + 1, word);
        }
        vis[x][y] = false;
        return ans;
    }

    public boolean exist(char[][] board, String word) {
        n = board.length;
        m = board[0].length;
        len = word.length();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (backtrack(i, j, board, -1, word)) {
                    return true;
                }
            }
        }
        return false;
    }
}