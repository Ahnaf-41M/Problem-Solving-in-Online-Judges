#include <bits/stdc++.h>
#define  ff           first
#define  ss           second
#define  MX           2000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int OK[MX];
vector<int> primes, adj[MX];
bool vis[MX];
void Sieve()
{
    for (int i = 3; i < MX; i += 2)
        OK[i] = 1;
    primes.pb(2);
    for (int i = 3; i < MX; i += 2) {
        if (OK[i]) {
            primes.pb(i);
            for (int j = i * i; j < MX; j += i)
                OK[j] = 0;
        }
    }
}
int dfs(int nd)
{
    int res = 1;
    vis[nd] = 1;
    for (int ch : adj[nd]) {
        if (!vis[ch]) {
            res += dfs(ch);
        }
    }
    return res;
}
void Solve(int tc)
{
    int n, m, k = 0;
    cin >> n >> m;

    if (m == 0) {
        cout << "-1\n";
        return;
    }
    while (m--) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            k = max(k, dfs(i));

    cout << primes[k - 1] << "\n";

    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        adj[i].clear();
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Sieve();
    int T = 1;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        Solve(tc);
    }

    return 0;
}