class Solution {
public:
    map<char, string> mp;
    vector<string> ans;
    string tmp;

    void pre_process() {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
    }
    void call(int i, string digits) {
        if (i == digits.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int j = 0; j < mp[digits[i]].size(); j++) {
            tmp.push_back(mp[digits[i]][j]);
            call(i + 1, digits);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        pre_process();
        call(0, digits);
        return ans;
    }
};