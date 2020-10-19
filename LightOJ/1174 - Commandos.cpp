#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 110

vector<int> adj[mx];
int n, m, dis[mx], par[mx];
bool vis[mx];

void bfs(int st)
{
	vis[st] = true;
	queue<int> Q;
	Q.push(st);
	par[st] = st;

	while (!Q.empty())
	{
		int nd = Q.front();
		Q.pop();

		for (int ch : adj[nd])
		{

			if (!vis[ch])
			{
				Q.push(ch);
				dis[ch] = dis[nd] + 1;
				vis[ch] = true;
				par[ch] = nd;
			}
		}
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
		W(m)
		{
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		int st, ed; cin >> st >> ed;
		vector<int> ds1,ds2;

		bfs(st);
        for(int i = 0; i< n; i++)
        	ds1.pb(dis[i]);
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		bfs(ed);
		for(int i = 0; i< n; i++)
        	ds2.pb(dis[i]);
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		int ans = 0;
		
		for (int i = 0; i < n; i++){
			adj[i].clear();
			ans = max(ans,ds1[i]+ds2[i]);
		}
		cout << "Case " << k << ": " << ans << endl;
	}

	return 0;
}