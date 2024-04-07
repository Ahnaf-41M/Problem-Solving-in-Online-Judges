class Solution {
    public String reverseWords(String s) {
        List<String> wordList = new ArrayList<String>();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                if (sb.length() > 0)
                    wordList.add(sb.toString());
                sb.setLength(0);
            } else {
                sb.append(s.charAt(i));
            }
        }
        if (sb.length() > 0)
            wordList.add(sb.toString());
        sb.setLength(0);

        for (int i = wordList.size() - 1; i >= 0; i--) {
            sb.append(wordList.get(i));
            if (i != 0)
                sb.append(" ");
        }

        return sb.toString();
    }
}