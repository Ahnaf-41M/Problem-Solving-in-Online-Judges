class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        int ansLen = 1;
        pair<int, int> ansPair = {0, 0};

        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            // for odd length
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > ansLen) {
                    ansLen = r - l + 1;
                    ansPair = {l, r};
                }
                l--, r++;
            }

            // for even length
            l = i - 1, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > ansLen) {
                    ansLen = r - l + 1;
                    ansPair = {l, r};
                }
                l--, r++;
            }
        }
        //cout << ansPair.first << " " << ansPair.second<<"\n";
        for (int i = ansPair.first; i <= ansPair.second; i++) {
            ans.push_back(s[i]);
        }
        return ans;
    }
};