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

char s[MX][MX];
bool vis[MX][MX];
int n, m, curLen;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
PII startPoint;

bool Valid(int x, int y)
{
	return (x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && s[x][y] == '.');
}
void dfs(int x, int y, int cnt)
{
	vis[x][y] = 1;
	if (curLen < cnt) {
		curLen = cnt;
		startPoint = {x, y};
	}
	for (int i = 0; i < 4; i++) {
		int tx = dx[i] + x;
		int ty = dy[i] + y;
		if (Valid(tx, ty)) dfs(tx, ty, cnt + 1);
	}
}
void Clear()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			vis[i][j] = false;
	curLen = 0;
	startPoint = { -1, -1};
}
void Solve(int tc)
{
	int res = 0;
	vector<PII> points;

	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> s[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (Valid(i, j)) {
				dfs(i, j, 0);
				points.pb(startPoint);
				curLen = 0;
			}
		}
	}
	Clear();
	for (auto it : points) {
		if (Valid(it.ff, it.ss)) {
			dfs(it.ff, it.ss, 0);
			res = max(curLen, res);
		}
	}
	cout << "Maximum rope length is " << res << ".\n";
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