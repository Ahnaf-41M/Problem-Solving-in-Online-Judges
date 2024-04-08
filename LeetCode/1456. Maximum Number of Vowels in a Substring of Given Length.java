class Solution {
    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    public int maxVowels(String s, int k) {
        int ans = 0, cntVowel = 0, n = s.length();
        char[] s2 = s.toCharArray();

        for (int i = 0; i < n; i++) {
            if (isVowel(s2[i]))
                cntVowel++;
            if (i - k + 1 >= 0) {
                ans = Math.max(ans, cntVowel);
                if (isVowel(s2[i - k + 1]))
                    cntVowel--;
            }
        }
        return ans;
    }
}