class Solution {
    public int calGcd(int n, int m) {
        if (m == 0)
            return n;
        return calGcd(m, n % m);
    }

    public String gcdOfStrings(String str1, String str2) {
        String s1 = str1.concat(str2), s2 = str2.concat(str1);
        if (!s1.equals(s2))
            return "";
        int n = str1.length(), m = str2.length();
        int gcd = calGcd(n, m);
        StringBuilder cur = new StringBuilder();
        for (int i = 0; i < gcd; i++) {
            cur.append(str1.charAt(i));
        }
        return cur.toString();
    }
}