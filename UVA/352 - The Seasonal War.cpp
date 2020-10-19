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

char s[50][50];
map<pair<int, int>, int> vis;
int n;

void call(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= n )
		return;
	if (s[x][y] == '0' || vis[ {x, y}])
		return;
	vis[ {x, y}] = 1;

	call(x - 1, y);
	call(x + 1, y);
	call(x, y - 1);
	call(x, y + 1);
	call(x - 1, y - 1);
	call(x + 1, y + 1);
	call(x + 1, y - 1);
	call(x - 1, y + 1);

}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i, j, cs = 0;

	while (cin >> n)
	{
		cs++;
		memset(s, 0, sizeof(s));
		vector<pair<int, int> > v;
		rep(i, n)
		{
			rep(j, n)
			{
				cin >> s[i][j];
				if (s[i][j] == '1')
					v.pb({i, j});
			}
		}
		int ans = 0;
		rep(i, v.size())
		{
			int a = v[i].first;
			int b = v[i].second;
			if (vis[ {a, b}] != 1)
			{
				call(a, b);
				ans++;
			}
		}
		cout << "Image number " << cs << " contains " << ans << " war eagles." << endl;
		vis.clear();
	}
}
