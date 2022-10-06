#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           1100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

long double factDigits[MX];

void Work1()
{
    for (int i = 1; i < MX; i++)
        factDigits[i] += factDigits[i - 1] + log10(i);
}
int Work2(int n, int base)
{
    int ans = n;
    for (int i = 2; i <= base; i++) {
        if (base % i) continue;
        int p = 0, expB = 0, m = n, curPow = i;
        while (base % i == 0)
            p++, base /= i;
        while (m) {
            expB += (m / i);
            m /= i;
        }
        ans = min(ans, expB / p);
    }
    return ans;
}
void Solve(int tc)
{
    int n, base;
    while (cin >> n >> base) {
        long double ans = factDigits[n] / log10(base);
        int digits = floor(ans) + 1;
        int zeros = Work2(n, base);

        cout << zeros << " " << digits << "\n";
    }

}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Work1();
    int T = 1;
    // cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}