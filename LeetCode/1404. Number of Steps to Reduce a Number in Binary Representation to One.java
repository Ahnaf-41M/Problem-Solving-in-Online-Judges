class Solution {
    public int numSteps(String s) {
        // int ans = 0;
        // StringBuilder sb = new StringBuilder(s);
        // sb.reverse();
        // while (sb.length() != 1 || sb.charAt(0) != '1') {
        // if (sb.charAt(0) == '1') {
        // boolean rem = true;
        // for (int i = 0; i < sb.length(); i++) {
        // if (rem) {
        // if (sb.charAt(i) == '1') {
        // sb.setCharAt(i, '0');
        // } else {
        // sb.setCharAt(i, '1');
        // rem = false;
        // }
        // }
        // }
        // if (rem)
        // sb.append('1');
        // }
        // else {
        // sb = new StringBuilder(sb.substring(1));
        // }
        // // System.out.println(sb.toString());
        // ans++;
        // }
        // return ans;

        int ans = 0, carry = 0;
        for (int i = s.length() - 1; i >= 1; i--) {
            int bit = s.charAt(i) - '0';
            if (bit == 0 && carry == 0) {
                ans++;
            } else {
                if (bit == 1 && carry == 1) {
                    ans++;
                } else {
                    ans += 2;
                }
                carry = 1;
            }
        }
        return ans + carry;
    }
}
