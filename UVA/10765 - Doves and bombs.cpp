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
#define mx 100005

vector<int> adj[mx];
int n, m;
int low[mx], disc[mx], pigeons[mx], timer, AP[mx];


void dfs(int nd, int parent)
{
	disc[nd] = low[nd] = timer++;
	int child = 0;

	for (int ch : adj[nd])
	{
		if (disc[ch] == -1)
		{
			//pigeons[ch]++;
			//pigeons[nd]++;
			child++;

			dfs(ch, nd);
			low[nd] = min(low[nd], low[ch]);

			if (parent == -1 && child > 1)
				pigeons[nd] = max(pigeons[nd], child - 1), AP[nd] = 1;
			if (low[ch] >= disc[nd] && parent != -1)
				pigeons[nd]++, AP[nd] = 1;



		}
		else if (ch != parent)
			low[nd] = min(low[nd], disc[ch]);
	}
}
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second > p2.second;
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m, n, m)
	{
		int x, y, i;
		vector<pair<int, int> > ans, tmp;
		timer = 0;

		memset(low, 0, sizeof(low));
		memset(disc, -1, sizeof(disc));
		memset(pigeons, 0, sizeof(pigeons));
		memset(AP, 0, sizeof(AP));

		while (cin >> x >> y)
		{
			if (x == -1 && y == -1)
				break;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		dfs(0, -1);
		rep(i, n)
		{
			if (AP[i])
				ans.pb({i, pigeons[i]});
		}
		if (ans.size() < m)
		{
			rep(i, n)
			{
				if (!AP[i])
					tmp.pb({i, pigeons[i]});
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		sort(tmp.begin(), tmp.end(), cmp);
		rep(i, m - ans.size())
		{
			ans.pb(tmp[i]);
		}
		rep(i, ans.size())
		{
			cout << ans[i].first << " " << ans[i].second << endl;
		}

	}

	return 0;
}