class Solution {
public:
    int solve(vector<int> v) {
        if (v.empty()) return 0;
        int res = -20, n = v.size(), prod = 1;
        int pref[n], suf[n];
        for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            if (i == 0) {
                pref[i] = v[i];
                suf[j] = v[j];
            } else {
                pref[i] = pref[i - 1] * v[i];
                suf[j] = suf[j + 1] * v[j];
            }
            prod *= v[i];
        }
        res = prod;
        for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            if (i - 1 >= 0) res = max(res, pref[i - 1]);
            if (j + 1 < n) res = max(res, suf[j + 1]);
        }
        return res;
    }
    int maxProduct(vector<int>& nums) {
        vector<int> tmp;
        int ans = -20;

        for (int x : nums) {
            if (x == 0) {
                ans = max({0, ans, solve(tmp)});
                tmp.clear();
            } else {
                tmp.push_back(x);
            }
        }
        ans = max(ans, solve(tmp));
        return ans;
    }
};