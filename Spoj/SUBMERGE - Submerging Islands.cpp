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
#define mx 100005

vector<int> adj[mx];
int n, m;
int low[mx], disc[mx], ap[mx], timer;

void dfs(int nd, int par)
{
	disc[nd] = low[nd] = timer++;
	int child = 0;

	for (int ch : adj[nd])
	{
		if (disc[ch] == -1)
		{
			child++;
			dfs(ch, nd);
			low[nd] = min(low[nd], low[ch]);

			if (par == -1 && child > 1)
				ap[nd] = 1;
			if (par != -1 && low[ch] >= disc[nd])
				ap[nd] = 1;
			
		}
		else if (par != ch)
			low[nd] = min(low[nd], disc[ch]);
	}
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m, n)
	{
		int x, y, i;
		timer = 0;
		memset(disc, -1, sizeof(disc));
		memset(low, 0, sizeof(low));
		memset(ap, 0, sizeof(ap));

		W(m)
		{
			cin >> x >> y;
			adj[x].pb(y); adj[y].pb(x);
		}
		for (i = 1; i <= n; i++)
			if (disc[i] == -1)
				dfs(i, -1);
		int ans = 0;

		for (i = 1; i <= n; i++)
			if (ap[i])
				ans++;
		cout << ans << endl;
		for(i = 1; i <= n; i++)
			adj[i].clear();

	}

	return 0;
}