class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        boolean flg1 = false, flg2 = false;

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                flg1 = true;
            }
        }
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                flg2 = true;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
                // System.out.print(matrix[i][j] + " ");
            }
            // System.out.println();
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
                // System.out.print(matrix[i][j] + " ");
            }
            // System.out.println();
        }
        if (flg1) for (int i = 0; i < n; i++) matrix[i][0] = 0;
        if (flg2) for (int j = 0; j < m; j++) matrix[0][j] = 0;

    }
}