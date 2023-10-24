#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         1005
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

vector<int> adj[MX];
bool vis[MX];
int cur;
void dfs(int nd)
{
    cur++;
    vis[nd] = 1;
    for (int ch : adj[nd])
        if (!vis[ch])
            dfs(ch);
}
void Clear(int n)
{
    for (int i = 1; i <= n; i++) vis[i] = false;
    cur = 0;
}
void Solve(int tc)
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m; cin >> m;
        while (m--) {
            int x; cin >> x;
            adj[x].pb(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        dfs(i);
        if (cur == n) ans++;
        Clear(n);
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) adj[i].clear();

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

}