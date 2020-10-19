#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long
#define clr(a) memset(a,0,sizeof(a))

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

char grid[22][22];
int n, m, dis[22][22];
int dx[] = {0, 0, -1, 1};
int dy[] = { -1, 1, 0, 0};
bool vis[22][22];
vector<int> ans;

bool is_valid(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	if (vis[x][y] || grid[x][y] == 'm' || grid[x][y] == '#')
		return false;
	return true;
}
void bfs(int x, int y)
{
	vis[x][y] = true;

	queue<pair<int, int> > Q;
	Q.push({x, y});

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
				vis[xx][yy] = true;
				Q.push({xx, yy});
				dis[xx][yy] = dis[tx][ty] + 1;
				if (grid[xx][yy] == 'a' || grid[xx][yy] == 'b' || grid[xx][yy] == 'c')
					{
						ans.pb(dis[xx][yy]); //Q.pop();
						//cout<<xx<<" "<<yy<<" "<<ans.back()<<endl;
					}
			}
			if (ans.size() == 3)
				break;
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
	int t; cin >> t;

	for (int k = 1; k <= t; k++)
	{
		cin >> n >> m;
		int x, y;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 'h')
					x = i, y = j;
			}
		}
		bfs(x, y);
		int res = *max_element(ans.begin(), ans.end());
		cout << "Case " << k << ": " << res << endl;
		ans.clear();
		clr(grid);
		clr(vis);
		clr(dis);

	}
}