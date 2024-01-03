class Solution {
public:
    set<string> dict;
    map<string, bool> dp;

    bool call(string s) {
        if (s.empty())
            return true;
        if (dp.count(s))
            return dp[s];

        for (int i = 0; i < s.size(); i++) {
            string s2 = s.substr(0, i + 1);
            if (dict.count(s2)) {
                if (call(s.substr(i + 1))) {
                    return dp[s] = true;
                }
            }
        }
        return dp[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto it : wordDict)
            dict.insert(it);
        return call(s);
    }
};