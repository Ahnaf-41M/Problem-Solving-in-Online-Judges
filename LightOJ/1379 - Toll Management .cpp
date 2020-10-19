#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 10010
#define INF 1000000000
#define pii pair<int,int>

int n, m, s, t, p;
vector<pii> adj[mx], revAdj[mx];
int dis1[mx], dis2[mx];

void Dijkstra(int nd, int type)
{
	if (!type) dis1[nd] = 0;
	else dis2[nd] = 0;

	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.push({0, nd});

	while (!Q.empty())
	{
		int node = Q.top().second;
		Q.pop();

		if (!type)
		{
			for (auto ch : adj[node])
			{
				if (dis1[node] + ch.second < dis1[ch.first])
				{
					dis1[ch.first] = dis1[node] + ch.second;
					Q.push({dis1[ch.first], ch.first});
				}
			}
		}
		else
		{
			for (auto ch : revAdj[node])
			{
				if (dis2[node] + ch.second < dis2[ch.first])
				{
					dis2[ch.first] = dis2[node] + ch.second;
					Q.push({dis2[ch.first], ch.first});
				}
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

	int tc;
	cin >> tc;

	for (int k = 1; k <= tc; k++)
	{
		cin >> n >> m >> s >> t >> p;
		for (int i = 1; i <= n; i++) {
			dis2[i] = INF;
			dis1[i] = INF;
		}

		W(m)
		{
			int x, y, w; cin >> x >> y >> w;
			adj[x].pb({y, w});
			revAdj[y].pb({x, w});
		}
		Dijkstra(s, 0);
		Dijkstra(t, 1);
		int ans = -1;

		for (int i = 1; i <= n; i++)
			for (auto ch : adj[i])
				if (dis2[ch.first] + dis1[i] + ch.second <= p)
					ans = max(ans, ch.second);


		cout << "Case " << k << ": " << ans << endl;

		for (int i = 1; i <= n; i++)
		{
			adj[i].clear();
			revAdj[i].clear();
		}
		ans = -1;
	}
}

