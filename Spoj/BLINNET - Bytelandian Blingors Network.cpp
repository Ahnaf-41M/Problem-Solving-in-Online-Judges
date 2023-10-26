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

vector<PII> adj[MX];
bool vis[MX];

int Prims(int stNode)
{
    int res = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, stNode});

    while (!q.empty()) {
        int node = q.top().ss;
        int wt = q.top().ff;
        q.pop();

        if (vis[node]) continue;
        vis[node] = true;
        res += wt;
        for (auto[wt, ch] : adj[node])
            if (!vis[ch])
                q.push({wt, ch});

    }
    return res;
}
void Clear(int n)
{
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
    }
}
void Solve(int tc)
{
    int n, mnCost = 1e15, stNode;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string city;
        int neighbours;
        cin >> city >> neighbours;
        while (neighbours--) {
            int node, cost;
            cin >> node >> cost;
            adj[i].pb({cost, node});
            if (mnCost > cost) {
                mnCost = cost;
                stNode = node;
            }
        }
    }
    cout << Prims(stNode) << "\n";
    Clear(n);
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