#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define N 1010

int grid[N][N];
int r, c, R, xx, yy, dis[N][N];
bool vis[N][N];
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool is_valid(int x, int y)
{
	if (x < 0 || x >= r || y < 0 || y >= c)
		return false;
	if (vis[x][y] || grid[x][y] == 1)
		return false;
	return true;
}
void BFS(int sx,int sy)
{
	int i;
	vis[sx][sy] = true;
	queue<pair<int, int> > Q;
	Q.push({sx, sy});

	while (!Q.empty())
	{
		int tx = Q.front().first;
		int ty = Q.front().second; Q.pop();

		rep(i, 4)
		{
			int tx1 = tx + dx[i];
			int ty1 = ty + dy[i];
			if (is_valid(tx1, ty1))
			{
				Q.push({tx1, ty1});
				vis[tx1][ty1] = true;
				dis[tx1][ty1] = dis[tx][ty] + 1;
			}
		}
	}
}
void reset()
{
	memset(grid, 0, sizeof(grid));
	memset(dis, 0, sizeof(dis));
	memset(vis, 0, sizeof(vis));
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i, sx, sy;
	while (cin >> r >> c, r)
	{
		cin >> R;
		rep(i, R)
		{
			int n, m, x; cin >> n >> m;
			W(m)
			{
				cin >> x;
				grid[n][x] = 1;
			}
		}
		cin >> sx >> sy >> xx >> yy;
		BFS(sx,sy);
		cout << dis[xx][yy] << endl;
		reset();
	}

	return 0;
}