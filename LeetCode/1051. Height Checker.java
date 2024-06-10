class Solution {
    public int heightChecker(int[] heights) {
        int n = heights.length;
        int[] expected = new int[n];
        int ans = 0;

        for (int i = 0; i < n; i++) {
            expected[i] = heights[i];
        }
        Arrays.sort(expected);

        for (int i = 0; i < heights.length; i++) {
            if (heights[i] != expected[i]) {
                ans++;
            }
        }
        return ans;
    }
}