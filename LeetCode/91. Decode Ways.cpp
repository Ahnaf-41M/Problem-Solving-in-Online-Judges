class Solution {
public:
    string str;
    int n;
    map<string, int> dp;
    map<string, char> mp;

    int call(string s) {
        if (s.empty())
            return 1;
        if (dp.count(s))
            return dp[s];

        int res = 0;
        string cur;
        cur.push_back(s[0]);
        if (mp.count(cur))
            res += call(s.substr(1));
        if (s.size() > 1) {
            cur.push_back(s[1]);
            if (mp.count(cur))
                res += call(s.substr(2));
        }
        return dp[s] = res;
    }
    int numDecodings(string s) {
        n = s.size();
        for (int i = 1; i <= 26; i++) {
            mp[to_string(i)] = 65 + i - 1;
        }
        return call(s);
    }
};