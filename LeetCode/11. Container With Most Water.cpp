class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        long long ans = 0;

        while (l <= r) {
            long long mn = min(height[l], height[r]);
            ans = max(ans, (r - l) * mn);
            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return ans;
    }
};