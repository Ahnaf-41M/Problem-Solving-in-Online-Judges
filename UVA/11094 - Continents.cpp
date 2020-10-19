#include<bits/stdc++.h>

#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(i,n)        for(i = 0; i < n; i++)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

char s[25][25], ch;
bool vis[25][25];
int n, m, cnt;

void call(int x, int y)
{
	if (y < 0) y = m - 1;
	else if (y >= m) y = 0;

	if (x < 0 || x >= n)
		return;

	if (vis[x][y] || ch != s[x][y])
		return;

	cnt++;
	vis[x][y] = true;

	call(x - 1, y);
	call(x + 1, y);
	call(x, y - 1);
	call(x, y + 1);

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
		memset(vis, false, sizeof(vis));
		memset(s, -1, sizeof(s));

		int i, j;
		cnt = 0;
		int ans = 0;

		rep(i, n)
		{
			rep(j, m)
			{
				cin >> s[i][j];
			}
		}
		cin >> i >> j;
		ch = s[i][j];
		call(i, j);//as we can't consider the continent he is already in

		rep(i, n)
		{
			rep(j, m)
			{
				cnt = 0;
				if (!vis[i][j] && ch == s[i][j])
					call(i, j);
				ans = max(cnt, ans);
			}
		}
		cout << ans << endl;
	}

	return 0;
}