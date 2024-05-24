class Solution {
    int[] freq = new int[26];
    int n;

    int calculateScore(String s, int[] score) {
        int ans = 0;
        boolean ok = true;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (freq[ch - 'a'] <= 0) {
                ok = false;
            }
            freq[ch - 'a']--;
            ans += score[ch - 'a'];
        }
        if (!ok)
            ans = 0;
        return ans;
    }

    int backtrack(int pos, String[] words, int[] score) {
        if (pos >= n)
            return 0;
        int res1 = 0, res2 = 0;
        res1 = calculateScore(words[pos], score) + backtrack(pos + 1, words, score);
        for (int i = 0; i < words[pos].length(); i++) {
            char ch = words[pos].charAt(i);
            freq[ch - 'a']++;
        }
        res2 = backtrack(pos + 1, words, score);
        return Math.max(res1, res2);
    }

    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        for (char ch : letters) {
            freq[ch - 'a']++;
        }
        n = words.length;
        return backtrack(0, words, score);
    }
}

// class Solution {
//     public int maxScoreWords(String[] words, char[] letters, int[] score) {
//         int[] cnt = new int[26];
//         for (char ch : letters) {
//             cnt[ch - 'a']++;
//         }

//         int n = words.length, ans = 0;
//         for (int i = 1; i < (1 << n); i++) {
//             int cur = 0;
//             boolean ok = true;
//             for (int j = 0; j < n; j++) {
//                 if ((i & (1 << j)) > 0) {
//                     for (int k = 0; k < words[j].length(); k++) {
//                         char ch = words[j].charAt(k);
//                         if (cnt[ch - 'a'] == 0) {
//                             ok = false;
//                         }
//                         cur += score[ch - 'a'];
//                         cnt[ch - 'a']--;
//                     }
//                 }
//             }
//             if (ok) {
//                 ans = Math.max(ans, cur);
//             }
//             for (int j = 0; j < n; j++) {
//                 if ((i & (1 << j)) > 0) {
//                     for (int k = 0; k < words[j].length(); k++) {
//                         char ch = words[j].charAt(k);
//                         cnt[ch - 'a']++;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// }