class Solution {
    int[] frq1 = new int[26];
    int[] frq2 = new int[26];
    public boolean isAnagram(String s, String t) {
        for (int i = 0; i < s.length(); i++) {
            frq1[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            frq2[t.charAt(i) - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (frq1[i] != frq2[i]) {
                return false;
            }
        }
        return true;
    }
}