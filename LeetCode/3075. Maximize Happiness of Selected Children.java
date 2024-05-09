class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        int j = happiness.length - 1, cur = 0;
        long ans = 0;
        while (j >= 0 && k > 0) {
            if (happiness[j] - cur < 0) break;
            ans += (happiness[j] - cur);
            cur++;
            k--;
            j--;
        }
        return ans;
    }
}