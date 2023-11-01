#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         505
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

char s[MX][MX];
bool vis[MX][MX];
int n, m, q, ans[MX][MX], cnt;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
vector<PII> v;

bool valid(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] != '#' && !vis[x][y]);
}
void dfs(int x, int y)
{
    v.pb({x, y});
    vis[x][y] = true;
    if (s[x][y] == 'C') cnt++;
    for (int i = 0; i < 4; i++) {
        int tx = dx[i] + x;
        int ty = dy[i] + y;
        if (valid(tx, ty))
            dfs(tx, ty);
    }
}
void Solve(int tc)
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> s[i][j];

    vector<PII> queries(q);
    for (auto &[x, y] : queries) cin >> x >> y;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (valid(i, j)) {
                cnt = 0;
                dfs(i, j);
                for (auto [x, y] : v) ans[x][y] = cnt;
                v.clear();
            }
        }
    }
    cout << "Case " << tc << ":\n";
    for (auto [x, y] : queries) cout << ans[x][y] << "\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vis[i][j] = false;
            ans[i][j] = 0;
        }
    }
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