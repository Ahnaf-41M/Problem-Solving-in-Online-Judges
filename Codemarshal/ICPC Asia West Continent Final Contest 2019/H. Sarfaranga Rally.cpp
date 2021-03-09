#include <bits/stdc++.h>
#include <ext/rope>

#define  pb   push_back
#define  int  long long
#define  endl "\n"
#define  MX   100005

#define  W(t)            while(t--)
#define  all(v)          v.begin(),v.end()
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  rep(i,a,b)      for(int i = a; i <= b; i++)
#define  irep(i,a,b)     for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

typedef pair<int, int> PII;
int grid[25][25], dis[25][25];
bool vis[25][25];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

bool Valid(int x, int y)
{
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}
void bfs()
{
	priority_queue < pair<int, PII> > Q;
	Q.push({grid[1][1], {1, 1}});
	vis[1][1] = true;
	dis[1][1] = grid[1][1];

	while (!Q.empty()) {
		auto cur = Q.top();
		int x = cur.second.first;
		int y = cur.second.second;
		Q.pop();

		rep(i, 0, 3) {
			int tx = dx[i] + x;
			int ty = dy[i] + y;

			if (Valid(tx, ty)) {
				if (dis[tx][ty] > dis[x][y] + grid[tx][ty]) {
					dis[tx][ty] = dis[x][y] + grid[tx][ty];
					Q.push({dis[tx][ty], {tx, ty}});
				}
			}
		}
	}
}

void reset()
{
	rep(i, 0, 24) {
		rep(j, 0, 24) {
			dis[i][j] = INT_MAX;
			vis[i][j] = false;
		}
	}
}
void Solve()
{
	reset();

	cin >> n >> m;

	rep(i, 1, n) rep(j, 1, m) cin >> grid[i][j];

	bfs();
	cout << dis[n][m] << endl;
	return;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	rep(k, 1, t) {
		cout << "Case " << k << ": Penalty = ";
		Solve();
	}

	return 0;
}