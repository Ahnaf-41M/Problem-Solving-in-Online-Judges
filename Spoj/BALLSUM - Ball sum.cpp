#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

void Solve(int tc)
{
    int n, k;
    while (cin >> n >> k) {
        if (n == -1)
            break;
        int x = (k / 2) + (k % 2);
        int y = k - x - 1;

        int numerator = (x * (x - 1) / 2) + (y * (y + 1) / 2);
        int denominator = n * (n - 1) / 2;
        int g = __gcd(numerator, denominator);

        numerator /= g, denominator /= g;
        if (numerator == 0)
            cout << "0\n";
        else
            cout << numerator << "/" << denominator << "\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}