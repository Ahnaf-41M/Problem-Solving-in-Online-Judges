class Solution {
    public int compress(char[] chars) {
        int n = chars.length;
        int curPos = 0;

        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && chars[j] == chars[i]) {
                j++;
            }
            chars[curPos++] = chars[i];
            if (j - i > 1) {
                char[] count = ("" + (j - i)).toCharArray();
                for (char ch : count) {
                    chars[curPos++] = ch;
                }
            }
            i = j - 1;
        }
        return curPos;
    }
}