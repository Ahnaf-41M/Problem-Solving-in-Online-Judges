class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = 0, j = 0;
        int m = s.length(), n = t.length();
        char[] s1 = t.toCharArray();
        char[] s2 = s.toCharArray();

        while (i < n) {
            if (j < m && s1[i] == s2[j]) {
                j++;
            }
            i++;
        }
        return j == m;
    }
}