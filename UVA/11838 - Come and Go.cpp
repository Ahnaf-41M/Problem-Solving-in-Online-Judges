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
int n, m, a, b, p, SCC, timer;
bool vis[mx];
int low[mx], disc[mx];
stack<int> S;

void dfs(int nd)
{
	vis[nd] = true;

	for (int ch : adj[nd])
	{
		if (!vis[ch])
			dfs(ch);
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
		int i;
		SCC = 0; timer = 0;
		W(m)
		{
			cin >> a >> b >> p;
			if (p == 1)
				adj[a].pb(b);
			else
			{
				adj[a].pb(b);
				adj[b].pb(a);
			}
		}
		bool ok = true;

		for (i = 1; i <= n; i++)
		{
			dfs(i);
			for (int j = 1; j <= n; j++)
				if (!vis[j]) { ok = false; break;}
				else vis[j] = false;
		}
		if (ok) cout << 1 << endl;
		else cout << 0 << endl;
		for (i = 1; i <= n; i++) {
			vis[i] = false;
			adj[i].clear();
		}
	}

	return 0;
}
