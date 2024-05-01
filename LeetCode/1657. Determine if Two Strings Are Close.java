class Solution {
    public boolean closeStrings(String word1, String word2) {
        int[] frq1 = new int[26];
        int[] frq2 = new int[26];

        for (char ch : word1.toCharArray())
            frq1[ch - 'a']++;
        for (char ch : word2.toCharArray())
            frq2[ch - 'a']++;

        for (int i = 0; i < 26; i++) {
            if ((frq1[i] == 0 && frq2[i] > 0)
                    || (frq2[i] == 0 && frq1[i] > 0)) {
                return false;
            }
        }
        Arrays.sort(frq1);
        Arrays.sort(frq2);

        return Arrays.equals(frq1,frq2);
    }
}