class Solution {
    class Node {
        boolean isWord;
        Node[] next = new Node[26];
    }
    Node root = new Node();

    public void insert(String s) {
        Node cur = this.root;
        for (char ch : s.toCharArray()) {
            int val = ch - 'a';
            if (cur.next[val] == null) {
                cur.next[val] = new Node();
            }
            cur = cur.next[val];
        }
        cur.isWord = true;
    }

    public String search(String s) {
        Node cur = this.root;
        for (int i = 0; i < s.length(); i++) {
            int val = s.charAt(i) - 'a';
            if (cur.next[val] == null) {
                return "";
            }
            cur = cur.next[val];
            if (cur.isWord)
                return s.substring(0, i + 1);
        }
        return "";
    }

    public String replaceWords(List<String> dictionary, String sentence) {
        StringBuilder ans = new StringBuilder();
        String[] ar = sentence.split(" ");

        for (String s : dictionary) {
            insert(s);
        }
        for (int i = 0; i < ar.length; i++) {
            String res = search(ar[i]);
            if (res == "") {
                ans.append(ar[i]);
            } else {
                ans.append(res);
            }
            ans.append(" ");
        }
        return ans.toString().trim();
    }
}