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

struct info
{
    int a, v, s;
    string name;
};

bool cmp(info x, info y)
{
    if (x.a > y.a) return true;
    else if (x.a == y.a && x.v > y.v) return true;
    else if (x.a == y.a && x.v == y.v && x.s < y.s) return true;
    else if (x.a == y.a && x.v == y.v && x.s == y.s && x.name < y.name) return true;
    else return false;
}
void Solve(int tc)
{
    int n;
    vector<info> v;
    cin >> n;

    while (n--) {
        info val;
        cin >> val.name >> val.a >> val.v >> val.s;
        v.pb(val);
    }
    sort(all(v), cmp);
    for (auto it : v) cout << it.name << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    //cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}