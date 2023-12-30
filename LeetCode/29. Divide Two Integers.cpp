class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        long long ans = 0;
        bool isPos = (dividend > 0 == divisor > 0);
        long long a = abs(dividend);
        long long b = abs(divisor);

        while (a >= b) {
            long long pow = 0;
            while (a >= (b << (pow + 1))) {
                pow++;
            }
            ans += 1 << pow;
            a = a - (b << pow);
        }

        if (ans == (1 << 31) && isPos) return INT_MAX;
        return isPos ? ans : -ans;
    }
};