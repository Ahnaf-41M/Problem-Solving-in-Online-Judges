#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         1000005
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

int dis1[MX], dis2[MX];
int n, m;
vector<PII> adj[MX], revAdj[MX];
const int inf = 1e18;
void bfs1()
{
    priority_queue<PII, vector<PII>> q;
    q.push({0, 1});
    dis1[1] = 0;
    while (!q.empty()) {
        int nd = q.top().ss;
        q.pop();

        for (auto ch : adj[nd]) {
            int cur = ch.ss, cost = ch.ff;
            if (cost + dis1[nd] < dis1[cur]) {
                dis1[cur] = cost + dis1[nd];
                q.push({dis1[cur], cur});
            }
        }
    }
}
void bfs2()
{
    priority_queue<PII, vector<PII>> q;
    q.push({0, 1});
    dis2[1] = 0;
    while (!q.empty()) {
        int nd = q.top().ss;
        q.pop();

        for (auto ch : revAdj[nd]) {
            int cur = ch.ss, cost = ch.ff;
            if (cost + dis2[nd] < dis2[cur]) {
                dis2[cur] = cost + dis2[nd];
                q.push({dis2[cur], cur});
            }
        }
    }
}
void Reset()
{
    for (int i = 1; i <= n; i++) {
        dis1[i] = dis2[i] = inf;
        adj[i].clear();
        revAdj[i].clear();
    }
}
void Solve(int tc)
{
    cin >> n >> m;
    Reset();
    while (m--) {
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].pb({c, y});
        revAdj[y].pb({c, x});
    }

    bfs1(); //from node 1 to other
    bfs2(); //from other to node 1

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += dis1[i] + dis2[i];
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

}