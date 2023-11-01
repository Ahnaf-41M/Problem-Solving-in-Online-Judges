#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define  ff         first
#define  ss         second
#define  MX         100005
#define  pb         push_back
#define  int        long long
#define  PII        pair<int, int>
#define  all(v)     v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>, //less_equal for multiset
    rb_tree_tag, tree_order_statistics_node_update>;

int dis[11][11];
char s[11][11];
int n, m, ans;
const int inf = 2e18;

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
void Reset()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dis[i][j] = -1;
}
bool valid(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] == '.' && dis[x][y] == -1);
}
bool valid2(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m && dis[x][y] == -1);
}
void bfs(int x, int y)
{
    // cout << x << " " << y << "\n";
    queue<PII> q;
    q.push({x, y});
    dis[x][y] = 0;
    while (!q.empty()) {
        x = q.front().ff;
        y = q.front().ss;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (valid2(tx, ty)) {
                dis[tx][ty] = dis[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }
    int cur = 0, ok = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] != '.') {
                if (dis[i][j] == -1)
                    ok = 0;
                int val = s[i][j] - '0';
                cur += (dis[i][j] / val) + (dis[i][j] % val != 0);
            }
        }
    }
    if (ok) ans = min(ans, cur);

}
void Solve(int tc)
{
    int num = 0;
    ans = inf;
    Reset();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> s[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            Reset();
            bfs(i, j);
            if (s[i][j] != '.') num++;
        }
    }
    cout << "Case " << tc << ": ";
    if (ans == inf) cout << "-1\n";
    else cout << ans << "\n";

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