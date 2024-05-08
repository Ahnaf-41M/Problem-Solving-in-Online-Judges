class Solution {

    public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        int[] sortedScore = score.clone();
        Arrays.sort(sortedScore);
        String[] ans = new String[n];

        for (int i = 0; i < n; i++) {
            int rank = Arrays.binarySearch(sortedScore, score[i]);
            if (rank == n - 1) {
                ans[i] = "Gold Medal";
            } else if (rank == n - 2) {
                ans[i] = "Silver Medal";
            } else if (rank == n - 3) {
                ans[i] = "Bronze Medal";
            } else {
                ans[i] = String.valueOf(n - rank);
            }
        }
        return ans;
    }
}