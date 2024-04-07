class Solution {
    private boolean isVowel(char ch) {
        return "aeiouAEIOU".indexOf(ch) != -1;
    }

    public String reverseVowels(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) {
                sb.append(s.charAt(i));
            }
        }
        sb.reverse();

        int j = 0;
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) {
                ans.append(sb.charAt(j++));
            } else {
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}