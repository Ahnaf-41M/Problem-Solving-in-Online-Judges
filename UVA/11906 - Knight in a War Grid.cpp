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


char grid[105][105];


pair<int,int> BFS(int r, int c, int m, int n)
{
	int dr[] = {m, m, -m, -m, n, -n, n, -n};
	int dc[] = { -n, n, n, -n, m, m, -m, -m};
	int x, y;
	bool vis[105][105] = {};
	int cnt[105][105] = {};

	
	queue<pair<int, int> > Q;

	Q.push({0, 0});
	vis[0][0] = true;

	while (!Q.empty())
	{
		auto p = Q.front(); Q.pop();
		set<pair<int, int> > st;

		for (int i = 0; i < 8; i++)
		{
			x = p.first + dr[i];
			y = p.second + dc[i];

			if (x >= 0 && y >= 0 && x < r && y < c && grid[x][y] != -1)
				st.insert({x, y});
		}
		for (auto id : st)
		{
			cnt[id.first][id.second]++;
			if (!vis[id.first][id.second])
			{
				Q.push({id.first,id.second});
				vis[id.first][id.second] = true;
			}
		}
	}
	int odd=0,even=0;
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			if((i==0&&j==0)||(grid[i][j]!=-1 && cnt[i][j]!=0))
			{
				if(cnt[i][j] & 1)
					odd++;
				else
					even++;
			}
		}
	}
	return {even,odd};

}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t, r, c, m, n, w,k;

	cin >> t;

	for(k = 1; k <= t; k++)
	{
		cin >> r >> c >> m >> n;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				grid[i][j] = 0;
			}
		}
		cin >> w;

		W(w)
		{
			int x, y;
			cin >> x >> y;
			grid[x][y] = -1;
		}
		pair<int, int> ans;
		ans = BFS(r, c, m, n);
		printf("Case %d: %d %d\n",k,ans.first,ans.second);
	}


	return 0;
}