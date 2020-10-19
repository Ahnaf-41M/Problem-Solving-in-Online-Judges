#include<bits/stdc++.h>

#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(i,a,n)      for(i = a; i < n; i++)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

char s[200][200];
bool vis[200][200];
int ans = 0, i, j;

void call(int x, int y)
{
	if (x < 0 || x >= i || y < 0 || y >= j)
		return;
	if (s[x][y] == '1' || vis[x][y])
		return;
	ans++;
	vis[x][y] = true;

	call(x - 1, y);
	call(x + 1, y);
	call(x, y - 1);
	call(x, y + 1);
}
int main()
{
	IOS
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, x, y, t;

	cin >> t;

	W(t)
	{
		string ss;
		cin >> x >> y;

		ans = 0; j = 0, i = 0;
		memset(s, 1, sizeof(s));
		memset(vis, false, sizeof(vis));

		cin.ignore(100, '\n');
		//getchar();

		while (getline(cin, ss))
		{
			if (ss == "")
				break;
			for (j = 0; j < ss.size(); j++)
				s[i][j] = ss[j];
			i++;

		}

		call(x - 1, y - 1);
		cout << ans << endl;
		if (t)
			cout << endl;
	}

	return 0;
}
