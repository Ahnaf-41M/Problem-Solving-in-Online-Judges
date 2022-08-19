#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           10000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int ans[MX], pre[MX];
int mod = 1e9 + 7;

void Work()
{
    //pattern = 0, 1, 2, 9, 44, 265, 1854, ...
    ans[2] = 1, ans[3] = 2;
    pre[2] = 2, pre[3] = 8;

    for (int i = 4; i < MX; i++) {
        if (i % 2 == 0) ans[i]++;
        ans[i] += pre[i - 1];
        ans[i] %= mod;
        pre[i] += pre[i - 1] + (i * ans[i]);
        pre[i] %= mod;
    }
}
void Solve(int tc)
{
    int n;
    cin >> n;
    cout << ans[n] << "\n";
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