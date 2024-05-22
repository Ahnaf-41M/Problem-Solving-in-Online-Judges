class Solution {
    List<List<String>> ans = new ArrayList<>();
    List<String> curList = new ArrayList<>();
    int n;

    boolean isPal(StringBuilder sb) {
        int len = sb.length();
        for (int i = 0; i < len; i++) {
            if (sb.charAt(i) != sb.charAt(len - i - 1)) {
                return false;
            }
        }
        return true;
    }

    void call(char[] s2, int pos) {
        if (pos == n) {
            // System.out.println("pos==n "+curList);
            ans.add(new ArrayList<>(curList));
            // System.out.println(ans);
            return;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = pos; i < n; i++) {
            sb.append(s2[i]);
            if (isPal(sb)) {
                curList.add(sb.toString());
                call(s2, i + 1);
                curList.remove(curList.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        n = s.length();
        char[] s2 = s.toCharArray();
        call(s2, 0);
        return ans;
    }
}