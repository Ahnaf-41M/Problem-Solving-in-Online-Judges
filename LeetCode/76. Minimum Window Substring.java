class Solution {
    int[] freq = new int[52];

    boolean ok() {
        for (int i = 0; i < 52; i++) {
            if (freq[i] > 0) {
                return false;
            }
        }
        return true;
    }
    void updateFreq(char ch, int x) {
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a' + 26] += x;
        } else {
            freq[ch - 'A'] += x;
        }
    }
    public String minWindow(String s, String t) {
        int n = s.length(), m = t.length();
        for (int j = 0; j < m; j++) {
            updateFreq(t.charAt(j), 1);
        }
        int st = -1, ed = -1, minLen = n + 1;
        int i = 0, j = 0;
        while (i < n) {
            updateFreq(s.charAt(i), -1);
            while (ok()) {
                if (minLen > i - j + 1) {
                    minLen = i - j + 1;
                    st = j;
                    ed = i + 1;
                }
                updateFreq(s.charAt(j), 1);
                j++;
            }
            i++;
        }
        if (st == -1) return "";
        else return s.substring(st, ed);
    }
}