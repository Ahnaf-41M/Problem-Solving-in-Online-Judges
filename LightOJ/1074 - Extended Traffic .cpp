#include<bits/stdc++.h>

#define endl "\n"
#define pb   push_back
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
using namespace std;

bool vis[205];
vector<pair<int, int> > adj[205];
int dis[205], n, q, m;
const int inf = 1e9;

void Bellman_Ford(int src)
{
	int i, j;
	rep(i, 1, n + 1) dis[i] = inf;
	dis[src] = 0;

	rep(i, 1, n) {
		rep(j, 1, n + 1) {
			for (auto ch : adj[j]) {
				int wt = ch.second;
				if (dis[j] + wt < dis[ch.first]) {
					dis[ch.first] = dis[j] + wt;
				}
			}
		}
	}
}
void dfs(int nd)
{
	vis[nd] = true;

	for (auto ch : adj[nd])
		if (!vis[ch.first])
			dfs(ch.first);
}
int main()
{
	int t, i, j, k;

	scanf("%d", &t);

	rep(k, 1, t + 1)
	{
		scanf("%d", &n);
		int a[n + 1];
		rep(i, 1, n + 1) cin >> a[i];

		scanf("%d", &m);

		W(m)
		{
			int x, y; scanf("%d%d", &x, &y);
			int w = a[y] - a[x];
			adj[x].pb({y, w * w * w});
		}

		Bellman_Ford(1);
		dfs(1);

		scanf("%d", &q);
		printf("Case %d:\n", k);
		W(q)
		{
			int node; cin >> node;

			if (!vis[node] || dis[node] < 3 || dis[node] == inf)
				printf("?\n");
			else
				printf("%d\n", dis[node]);
		}
		rep(i, 1, n + 1) {
			vis[i] = false;
			dis[i] = inf;
			adj[i].clear();
		}

	}
	return 0;
}