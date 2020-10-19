#include<bits/stdc++.h>

#define endl "\n"
#define pb   push_back
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
using namespace std;

struct Graph
{
	ll x, y, wt;
};

ll n, m, ans, ap_cost, arprt, par[10005];
Graph adj[100005];

bool cmp(Graph a, Graph b)
{
	return a.wt < b.wt;
}
ll root(ll v)
{
	if (par[v] < 0) return v;
	else return par[v] = root(par[v]);
}
void Kruskals()
{
	ll i, j;

	rep(i, 0, m)
	{
		ll a, b, c, r1, r2;
		a = adj[i].x; b = adj[i].y;
		c = adj[i].wt;

		r1 = root(a); r2 = root(b);

		if (r1 != r2)
		{
			par[r1] = r2;
			if (c >= ap_cost) {
				ans += ap_cost;
				arprt++;
			}
			else
				ans += c;
		}
	}
}
void CLEAR()
{
	ll i;

	rep(i, 1, n + 1) par[i] = 0;
	rep(i, 0, m) {
		adj[i].x = 0; adj[i].y = 0;
		adj[i].wt = 0;
	}
	ans = 0, arprt = 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t, i, j, k;
	scanf("%lld", &t);

	rep(i, 1, t + 1)
	{
		scanf("%lld%lld%lld", &n, &m, &ap_cost);
		rep(j, 0, m)
		{
			ll x, y, c;
			scanf("%lld%lld%lld", &x, &y, &c);
			adj[j].x = x; adj[j].y = y;
			adj[j].wt = c;
		}

		rep(j, 1, n + 1) par[j] = -1;
		sort(adj, adj + m, cmp);
		Kruskals();

		rep(j, 1, n + 1) {
			if (par[j] < 0) {
				arprt++;
				ans += ap_cost;
			}
		}
		printf("Case %lld: %lld %lld\n", i, ans, arprt);

		CLEAR();
	}
}