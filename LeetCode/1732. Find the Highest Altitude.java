class Solution {
    public int largestAltitude(int[] gain) {
        int prev = 0, ans = 0;
        for (int i = 0; i < gain.length; i++) {
            prev = gain[i] + prev;
            ans = Math.max(prev, ans);
        }
        return ans;
    }
}