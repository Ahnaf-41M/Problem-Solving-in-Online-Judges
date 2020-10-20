#include<bits/stdc++.h>

#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define N 1100

char grid[N][N];
bool vis[N][N];
int n, m, q, x, y, dis[N][N];
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_valid(int a, int b)
{
	if (a < 1 || a > n || b < 1 || b > m)
		return false;
	if (vis[a][b] || grid[a][b] == '*')
		return false;
	return true;
}
void Dijkstra(int x, int y)
{
	vis[x][y] = true;
	queue<pair<int, int> > Q;
	Q.push({x, y});
	dis[x][y] = 0;

	while (!Q.empty())
	{
		int tx = Q.front().first;
		int ty = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = tx + dx[i];
			int yy = ty + dy[i];

			if (is_valid(xx, yy))
			{
				Q.push({xx, yy});
				vis[xx][yy] = true;
				dis[xx][yy] = dis[tx][ty] + 1;
			}
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
	int i, j;
	memset(dis, -1, sizeof(dis));
	cin >> n >> m >> q;	

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> grid[i][j];
	cin >> x >> y;
	Dijkstra(x, y);
	W(q)
	{
		int u, v; cin >> u >> v;
		cout << dis[u][v] << endl;
	}
	return 0;
}