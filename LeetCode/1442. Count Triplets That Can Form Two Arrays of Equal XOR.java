class Solution {
    public int countTriplets(int[] arr) {
        int n = arr.length;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cur = arr[i];
            for (int j = i + 1; j < n; j++) {
                cur = cur ^ arr[j];
                if (cur == 0) {
                    ans += (j - i);
                }
            }
        }
        return ans;
    }
}