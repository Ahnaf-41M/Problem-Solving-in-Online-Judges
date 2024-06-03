class Solution {
    public int appendCharacters(String s, String t) {
        int n = s.length(), m = t.length();
        int j = 0, i = 0;
        while (i < n) {
            if (j < m && s.charAt(i) == t.charAt(j))
                j++;
            i++;
        }
        return m - j;
    }
}