class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int i = 0, j = 0, cur = 0, ans = 0;
        int n = s.length();

        while (i < n) {
            while (j < n && cur + Math.abs(s.charAt(j) - t.charAt(j)) <= maxCost) {
                cur += Math.abs(s.charAt(j) - t.charAt(j));
                j++;
            }
            ans = Math.max(ans, j - i);
            cur -= Math.abs(s.charAt(i) - t.charAt(i));
            i++;
        }
        return ans;
    }
}