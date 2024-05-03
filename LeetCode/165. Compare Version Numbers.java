class Solution {
    public int compareVersion(String version1, String version2) {
        int n = version1.length(), m = version2.length();
        int i = 0, j = 0;

        while (i < n || j < m) {
            int res1 = 0, res2 = 0;
            while (i < n && version1.charAt(i) != '.') {
                res1 = res1 * 10 + (version1.charAt(i) - '0');
                i++;
            }
            while (j < m && version2.charAt(j) != '.') {
                res2 = res2 * 10 + (version2.charAt(j) - '0');
                j++;
            }
            if (res1 > res2)
                return 1;
            else if (res1 < res2)
                return -1;
            i++;
            j++;
        }
        return 0;
    }
}