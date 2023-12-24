class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        char grid[1005][1005];
        int n = s.size();
        int row = -1, col = 0;
        bool flg = 1;

        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                grid[i][j] = '#';
            }
        }
        for (int i = 0; i < n; i++) {
            if (flg == 1) {
                row++;
                grid[row][col] = s[i];
            }
            else {
                row--, col++;
                grid[row][col] = s[i];
            }
            if (row == numRows - 1) {
                flg = 0;
            }
            else if (row == 0) {
                flg = 1;
            }
        }
        string ans;
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                if (grid[i][j] != '#') {
                    ans.push_back(grid[i][j]);
                }
            }
        }
        return ans;

    }
};