class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> v;
        v.push_back({1, "I"});
        v.push_back({4, "IV"});
        v.push_back({5, "V"});
        v.push_back({9, "IX"});
        v.push_back({10, "X"});
        v.push_back({40, "XL"});
        v.push_back({50, "L"});
        v.push_back({90, "XC"});
        v.push_back({100, "C"});
        v.push_back({400, "CD"});
        v.push_back({500, "D"});
        v.push_back({900, "CM"});
        v.push_back({1000, "M"});

        string ans;

        while (num > 0) {
            for (int i = 12; i >= 0; i--) {
                if (v[i].first <= num) {
                    num -= v[i].first;
                    ans += v[i].second;
                    break;
                }
            }
        }

        return ans;

    }
};