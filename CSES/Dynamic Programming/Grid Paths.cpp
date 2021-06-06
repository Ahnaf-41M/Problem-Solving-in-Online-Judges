#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           1005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int dp[MX][MX], n, mod = 1e9 + 7;
char grid[MX][MX];

int call(int x, int y)
{
	if (x == n && y == n && grid[x][y] == '.') return 1;
	if (x > n || y > n || x < 1 || y < 1 || grid[x][y] == '*') return 0;
	if (dp[x][y] != -1) return dp[x][y];

	int r1 = call(x + 1, y);
	int r2 = call(x, y + 1);

	return dp[x][y] = ((r1 % mod) + (r2 % mod)) % mod;
}
void Solve(int tc)
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	rep(i, 1, n) rep(j, 1, n) cin >> grid[i][j];

	cout << call(1, 1);
	return;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T = 1;
	//cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}