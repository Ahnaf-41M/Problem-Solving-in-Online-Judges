class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> ans = new ArrayList<Boolean>();
        int mx = 0, n = candies.length;
        for (int i = 0; i < n; i++) {
            mx = Math.max(mx, candies[i]);
        }
        for (int i = 0; i < n; i++) {
            if (candies[i] + extraCandies >= mx) {
                ans.add(true);
            } else {
                ans.add(false);
            }
        }
        return ans;
    }
}