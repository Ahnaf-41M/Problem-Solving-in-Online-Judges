#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

bool cmp1(PII x, PII y)
{
    return x.ss > y.ss;
}
bool cmp2(PII x, PII y)
{
    return x.ff < y.ff;
}
void Solve(int tc)
{
    int n, m, k, ans = 0;
    vector<PII> v;

    cin >> n >> m >> k;

    char s[n][m];
    rep(i, 0, n - 1) {
        int off = 0;
        rep(j, 0, m - 1) {
            cin >> s[i][j];
            off += (s[i][j] == '.');
        }
        v.pb({m - off, off});
    }
    sort(all(v), cmp1);

    rep(i, 0, n - 1) {
        if (v[i].ff < v[i].ss && k) {
            swap(v[i].ff, v[i].ss);
            k--;
        }
    }

    if (k & 1) sort(all(v), cmp2);
    rep(i, 0, n - 1) {
        if (k & 1) {
            swap(v[i].ff, v[i].ss);
            k = 0;
        }
        ans += v[i].ff;
    }
    cout << ans << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}