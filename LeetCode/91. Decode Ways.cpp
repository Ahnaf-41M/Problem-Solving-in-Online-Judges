class Solution {
public:
    string str;
    int n;
    int dp[101];
    int call(int pos) {
        if (pos >= n)
            return 1;
        if (str[pos] == '0')
            return 0;
        if (dp[pos] != -1)
            return dp[pos];

        int res = call(pos + 1);
        if (pos + 1 < n &&
                (str[pos] == '1' || (str[pos] == '2' && str[pos + 1] <= '6'))) {
            res += call(pos + 2);
        }

        return dp[pos] = res;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        n = s.size();
        str = s;
        return call(0);
    }
};
// class Solution {
// public:
//     string str;
//     int n;
//     map<string, int> dp;
//     map<string, char> mp;

//     int call(string s) {
//         if (s.empty())
//             return 1;
//         if (dp.count(s))
//             return dp[s];

//         int res = 0;
//         string cur;
//         cur.push_back(s[0]);
//         if (mp.count(cur))
//             res += call(s.substr(1));
//         if (s.size() > 1) {
//             cur.push_back(s[1]);
//             if (mp.count(cur))
//                 res += call(s.substr(2));
//         }
//         return dp[s] = res;
//     }
//     int numDecodings(string s) {
//         n = s.size();
//         for (int i = 1; i <= 26; i++) {
//             mp[to_string(i)] = 65 + i - 1;
//         }
//         return call(s);
//     }
// };