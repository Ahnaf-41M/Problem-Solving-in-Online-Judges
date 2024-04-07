class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int n = word1.size(), m = word2.size();
        int i = 0, l = min(n, m);

        while (i < l) {
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
            i++;
        }
        while (i < n) {
            ans.push_back(word1[i]);
            i++;
        }
        while (i < m) {
            ans.push_back(word2[i]);
            i++;
        }
        return ans;

    }
};