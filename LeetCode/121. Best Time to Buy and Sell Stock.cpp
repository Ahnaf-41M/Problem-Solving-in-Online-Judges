class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Solution 1 O(nlogn)
        // multiset<int, greater<int>> s;
        // for(int x : prices) {
        //     s.insert(x);
        // }
        // int ans = 0;
        // for(int x : prices) {
        //     s.erase(s.find(x));
        //     ans = max(ans, (*s.begin()) - x);
        // }

        // Solution 2 O(n)
        int mx = 0, ans = 0;
        for (int i = prices.size() - 1; i >= 0; i--) {
            mx = max(mx, prices[i]);
            ans = max(ans, mx - prices[i]);
        }
        return ans;
    }
};