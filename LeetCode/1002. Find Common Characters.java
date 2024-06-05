class Solution {
    int[][] cnt = new int[101][26];

    public List<String> commonChars(String[] words) {
        int n = words.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                cnt[i][words[i].charAt(j) - 'a']++;
            }
        }

        List<String> ans = new ArrayList<>();
        for (int j = 0; j < 26; j++) {
            int mn = 10000;
            for (int i = 0; i < n; i++) {
                mn = Math.min(mn, cnt[i][j]);
            }
            while (mn > 0) {
                ans.add(String.valueOf((char)(j + 'a')));
                mn--;
            }
        }
        return ans;
    }
}