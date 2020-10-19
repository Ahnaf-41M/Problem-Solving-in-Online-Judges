#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 100005
#define pii pair<ll,ll>
#define INF LONG_MAX

vector<pii> adj[mx];
ll dis[mx], n, m, s, t;

void Dijkstra(ll st, ll ed)
{
	dis[st] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	Q.push({0, st});

	while (!Q.empty())
	{
		ll nd = Q.top().second;
		Q.pop();

		for (auto ch : adj[nd])
		{
			if (dis[ch.second] > dis[nd] + ch.first)
			{
				dis[ch.second] = dis[nd] + ch.first;
				Q.push({dis[ch.second], ch.second});
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
	int tc, k = 0; scanf("%d", &tc);

	W(tc)
	{
		scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
		W(m)
		{
			ll x, y, w; scanf("%lld%lld%lld", &x, &y, &w);
			adj[x].pb({w, y});
			adj[y].pb({w, x});
		}
		for (int i = 0; i < n; i++) dis[i] = INF;
		Dijkstra(s, t);
		if (dis[t] == INF)
			printf("Case #%d: unreachable\n", ++k);
		else
			printf("Case #%d: %lld\n", ++k, dis[t]);
		for (int i = 0; i < n; i++)
			adj[i].clear();
	}
	return 0;
}