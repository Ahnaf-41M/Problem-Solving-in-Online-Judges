#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define inf 1000000000
#define ff first
#define ss second
#define pii pair<int,pair<int,int> >

int n, m, dis[1010][1010];
char s[1010][1010];
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	return true;
}

void _0_1BFS()
{
	int i;
	dis[0][0] = 0;

	deque<pair<int, int> >  Q;

	Q.push_front({0, 0});

	while (!Q.empty())
	{
		int x = Q.front().ff;
		int y = Q.front().ss;
		Q.pop_front();

		rep(i, 0, 4)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];

			if (valid(tx, ty))
			{
				int val;
				val = (s[x][y] == s[tx][ty] ? 0 : 1);
				if (dis[tx][ty] > dis[x][y] + val)
				{
					dis[tx][ty] = dis[x][y] + val;
					if (val == 0) Q.push_front({tx, ty});
					else Q.push_back({tx, ty});
				}
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
	int t, j, i;

	cin >> t;

	W(t)
	{
		cin >> n >> m;

		rep(i, 0, n) {
			rep(j, 0, m) {
				cin >> s[i][j];
				dis[i][j] = inf;
			}
		}
		_0_1BFS();
		cout << dis[n - 1][m - 1] << endl;
	}

	return 0;
}