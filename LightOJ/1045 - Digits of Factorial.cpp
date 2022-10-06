#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           1000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

double factDigits[MX];

void Work()
{
    for (int i = 1; i < MX; i++)
        factDigits[i] += factDigits[i - 1] + log10(i);
}
void Solve(int tc)
{
    int n, base;
    cin >> n >> base;

    double ans = factDigits[n] / log10(base);
    n = floor(ans) + 1;
    cout << "Case " << tc << ": " << n << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Work();
    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}