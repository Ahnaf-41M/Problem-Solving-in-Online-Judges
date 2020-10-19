/*Push all boundary cells to binary heap( min heap)
 Extract top element and in one go identify the final height of
 all its neighbors.( If neighbor's original height is greater
 than top element then it wont retain any water otherwise
 it can retain water equivalent to difference in heights).
 Now push these neighbors for which we have the final heights
  already to min heap*/
#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define pii pair<int,pair<int,int> >

bool vis[102][102];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

bool valid(int x, int y)
{
	return (x >= 1 && y >= 1 && x <= n && y <= m && !vis[x][y]);
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t, i, j;

	cin >> t;

	W(t)
	{
		cin >> n >> m;
		int a[n + 1][m + 1];

		rep(i, 1, n + 1) {
			rep(j, 1, m + 1) {
				cin >> a[i][j];
			}
		}
		priority_queue<pii, vector<pii>, greater<pii> > Q;

		rep(i, 1, n + 1) {
			Q.push({a[i][1], {i, 1}});
			Q.push({a[i][m], {i, m}});
			vis[i][1] = true;
			vis[i][m] = true;
		}
		rep(j, 1, m + 1) {
			Q.push({a[1][j], {1, j}});
			Q.push({a[n][j], {n, j}});
			vis[1][j] = true;
			vis[n][j] = true;
		}
		int ans = 0;

		while (!Q.empty())
		{
			int cur_height = Q.top().first;
			int x = Q.top().second.first;
			int y = Q.top().second.second;

			Q.pop();

			rep(i, 0, 4) {
				int tx = x + dx[i];
				int ty = y + dy[i];

				if (valid(tx, ty)) {
					if (cur_height > a[tx][ty]) {
						ans += (cur_height - a[tx][ty]);
						a[tx][ty] = cur_height;
					}
					vis[tx][ty] = true;
					Q.push({a[tx][ty], {tx, ty}});
				}
			}
		}
		cout << ans << endl;

		ans = 0;
		clr(vis);
	}

	return 0;
}