#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define pii pair<ll,ll>
#define ll long long

vector<pii> adj[11000];
ll dis[1100];
ll N, E, T, M, ans;

void Dijkstra(int st)
{
	dis[st] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.push({0, st});

	while (!Q.empty())
	{
		ll node = Q.top().second;
	    Q.pop();

		for (auto ch : adj[node])
		{
			if (dis[ch.second] > dis[node] + ch.first)
			{
				dis[ch.second] = dis[node] + ch.first;
				Q.push({dis[ch.second], ch.second});
			}
		}
	}
	if(dis[E] <= T)
		ans++;

}
int main()
{
	//freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tc; scanf("%d", &tc);

	while (tc--)
	{
		scanf("%lld%lld%lld%lld", &N, &E, &T, &M);

		while (M--)
		{
			ll x, y, Time; scanf("%lld%lld%lld", &x, &y, &Time);
			adj[x].push_back({Time, y});
		}
		for (ll i = 1; i <= N; i++)
		{
			for (ll j = 1; j <= N; j++) dis[j] = INF;
			Dijkstra(i);
		}
		printf("%lld\n", ans);
		if (tc) printf("\n");
		ans = 0;
		for (int i = 1; i <= N; i++) adj[i].clear();
	}
}