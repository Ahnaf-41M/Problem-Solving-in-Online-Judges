#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         10005
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

int C, B, S, T;
vector<int> adj[MX];
int dp[MX], indeg[MX];
const int mod = 1e9 + 7;
vector<int> Kahns()
{
    queue<int> q;
    vector<int> res;
    for (int i = 1; i <= C; i++)
        if (!indeg[i])
            q.push(i);
    while (!q.empty()) {
        int nd = q.front();
        q.pop();
        res.pb(nd);
        for (int ch : adj[nd]) {
            indeg[ch]--;
            if (!indeg[ch])
                q.push(ch);
        }
    }
    return res;
}
int find_path()
{
    vector<int> v = Kahns();
    dp[S] = 1;
    for (int i : v) {
        for (int j : adj[i]) {
            dp[j] += dp[i];
            dp[j] %= mod;
        }
    }
    return dp[T];
}
void Clear()
{
    for (int i = 1; i <= C; i++) {
        adj[i].clear();
        dp[i] = 0;
        indeg[i] = 0;
    }
}
void Solve(int tc)
{
    cin >> C >> B >> S >> T;
    for (int i = 0; i < B; i++) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        indeg[y]++;
    }
    cout << find_path() << "\n";
    Clear();
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