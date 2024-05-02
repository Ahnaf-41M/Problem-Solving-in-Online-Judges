class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (x, y) -> Integer.compare(x[0], y[0]));
        int prev = 1000000000, ans = 0;
        int n = intervals.length;

        for (int i = n - 1; i >= 0; i--) {
            //System.out.println(intervals[i][0] +" "+intervals[i][1]);
            if (prev < intervals[i][1]) ans++;
            else prev = intervals[i][0];
        }
        return ans;
    }
}