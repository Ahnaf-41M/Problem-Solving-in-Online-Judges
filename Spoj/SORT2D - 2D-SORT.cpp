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

bool cmp(PII a, PII b)
{
    return (a.ff > b.ff) || (a.ff == b.ff && a.ss < b.ss);
}
void Solve(int tc)
{
    int n;
    vector<PII> v;

    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        v.pb({x, y});
    }

    sort(all(v), cmp);
    reverse(all(v));
    for (auto it : v)
        cout << it.ff << " " << it.ss << "\n";
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