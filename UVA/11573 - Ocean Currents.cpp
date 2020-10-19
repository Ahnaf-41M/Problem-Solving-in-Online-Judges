#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define N 1010
#define inf 1000000000

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m;
char s[N][N];
int dis[N][N];

bool valid(int x, int y)
{
	return ((x >= 0 && y >= 0 && x < n && y < m));
}
void BFS(int sx, int sy)
{
	int i, j;

	dis[sx][sy] = 0;

	deque<pair<int, int> > Q;
	Q.push_front({sx, sy});

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;

		Q.pop_front();
		int ind = s[x][y] - '0';
		int ix = x + dx[ind];
		int iy = y + dy[ind];
		if (valid(ix, iy) && dis[ix][iy] > dis[x][y])
		{
			dis[ix][iy] = dis[x][y];
			Q.push_front({ix, iy});
		}

		rep(i, 0, 8)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];

			if (valid(tx, ty) && dis[tx][ty] > dis[x][y] + 1)
			{
				dis[tx][ty] = dis[x][y] + 1;
				Q.push_back({tx, ty});
			}
		}

	}

}
void RESET()
{
	int i, j;
	rep(i, 0, n) {
		rep(j, 0, m) {
			dis[i][j] = inf;
		}
	}
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while (cin >> n >> m)
	{
		int i, j;
		rep(i, 0, n) {
			rep(j, 0, m) {
				cin >> s[i][j];
				dis[i][j] = inf;
			}
		}
		int k; cin >> k;
		W(k)
		{
			int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
			sx--, sy--; ex--, ey--;
			BFS(sx, sy);
			cout << dis[ex][ey] << endl;
			RESET();
		}
	}

	return 0;
}