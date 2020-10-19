#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m, ans;
char grid[22][22];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool vis[22][22];

bool valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	if (grid[x][y] == '#' || vis[x][y])
		return false;
	return true;
}
void call(int x, int y)
{
	vis[x][y] = true;

	for (int i = 0; i < 4; i++) 
	{
		int tx = dx[i] + x;
		int ty = dy[i] + y;
		if (valid(tx, ty))
			call(tx, ty);
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
		swap(n,m);
		int i, j, sx, sy;
		rep(i, 0, n) {
			rep(j, 0, m) {
				cin >> grid[i][j];
				if (grid[i][j] == '@')
					sx = i, sy = j;
			}
		}
		call(sx, sy);
		int res = 0;
		rep(i,0,n){
			rep(j,0,m){
				if(vis[i][j])
					res++;
			}
		}
		clr(vis);
		cout << "Case " << k << ": " << res << endl;
		ans = 0;
	}

	return 0;
}