#include<bits/stdc++.h>

#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(a,b,c)      for(int i = a; i < b; i+=c)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, k, i , j, x, y, ans;

int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m >> k && n && m && k)
	{
		string s2;
		char dir;
		char s[n+3][m+3];

		ans = 0;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				cin >> s[i][j];
				if (s[i][j] == 'N' || s[i][j] == 'O' || s[i][j] == 'S'
				        || s[i][j] == 'L')
				{
					dir = s[i][j];
					x = i, y = j;
				}
			}
		}
		cin >> s2;

		for (i = 0; i < s2.size(); i++)
		{
			if (s2[i] == 'D')
			{
				if (dir == 'N') dir = 'L';
				else if (dir == 'L') dir = 'S';
				else if (dir == 'S') dir = 'O';
				else if (dir == 'O') dir = 'N';
			}
			else if (s2[i] == 'E')
			{
				if (dir == 'N') dir = 'O';
				else if (dir == 'L') dir = 'N';
				else if (dir == 'S') dir = 'L';
				else if (dir == 'O') dir = 'S';
			}
			else
			{
				int tx = x, ty = y;
				if (dir == 'N') tx -= 1;
				else if (dir == 'L') ty += 1;
				else if (dir == 'S') tx += 1;
				else if (dir == 'O') ty -= 1;

				if ((tx >= 1 && tx <= n) && (ty >= 1 && ty <= m))
				{
					if (s[tx][ty] != '#')
					{
						if (s[tx][ty] == '*')
						{
							ans++;
							s[tx][ty] = '.';
						}
						x = tx; y = ty;
					}
					
				}
			}
		}
		cout << ans << endl;

	}

	return 0;
}