#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 30
#define ff first
#define ss second

vector<int> adj[mx];
vector<pair<pair<int, int>, int> > ans;
int dis[mx], n;
bool vis[mx];

void bfs(int nd)
{
	vis[nd] = true;
	queue<int> Q;
	Q.push(nd);

	while (!Q.empty())
	{
		int fr = Q.front(); Q.pop();
		for (int ch : adj[fr])
		{
			if (!vis[ch])
			{
				vis[ch] = true;
				Q.push(ch);
				dis[ch] = dis[fr] + 1;
			}
		}
	}
}
int main()
{
	//IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int cnt = 0, tc = 1;
	int k = 1;

	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			adj[1].pb(x);
			adj[x].pb(1);
		}
		for (int i = 2; i <= 19; i++)
		{
			cin >> n;
			W(n)
			{
				int x; scanf("%d", &x);
				adj[i].pb(x);
				adj[x].pb(i);
			}
			cnt++;
		}

		cin >> n;

		W(n)
		{
			int st, ed; scanf("%d%d", &st, &ed);
			bfs(st);
			ans.pb({{st, ed}, dis[ed]});
			for (int i = 1; i <= 20; i++) {
				vis[i] = false;
				dis[i] = 0;
			}
		}
		cout << "Test Set #" << tc++ << "\n";

		for (int i = 0; i < ans.size(); i++)
			printf("%2d to %2d: %d\n", ans[i].ff.ff, ans[i].ff.ss, ans[i].ss);
		for (int i = 0; i <= 20; ++i)
			adj[i].clear();
		ans.clear();
		cout << endl;
	}


	return 0;
}