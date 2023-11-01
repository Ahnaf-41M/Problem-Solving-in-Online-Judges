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
int n, m, money[MX], avg, cur;

void dfs(int nd)
{
    vis[nd] = true;
    int need = money[nd] - avg;
    money[nd] = avg;
    cur += need;
    for (int ch : adj[nd])
        if (!vis[ch])
            dfs(ch);
}
void Solve(int tc)
{
    int sum = 0;
    bool ok = 1;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> money[i];
        sum += money[i];
    }
    while (m--) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    avg = sum / n;
    cur = 0;
    // cout << avg << "\n";
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            if (cur != 0) ok = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
    }
    cout << "Case " << tc << ": " << (ok ? "Yes\n" : "No\n");
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