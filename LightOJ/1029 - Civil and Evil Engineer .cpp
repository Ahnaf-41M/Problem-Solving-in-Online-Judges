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

ll par1[105], par2[105], n, ind, ans;
Graph adj[20005];

bool cmp(Graph a, Graph b)
{
	return a.wt < b.wt;
}
ll root(ll v, ll type)
{
	if (type) {
		if (par2[v] < 0) {
			return v;
		}
		else return par2[v] = root(par2[v], type);
	}
	else {
		if (par1[v] < 0) {
			return v;
		}
		else return par1[v] = root(par1[v], type);
	}
}
void Kruskals()
{
	ll i, j;

	for (i = 0, j = ind - 1; i<ind, j >= 0; i++, j--)
	{
		ll a1, a2, b1, b2, w1, w2;
		ll r1, r2, r3, r4;

		a1 = adj[i].x, a2 = adj[j].x;
		b1 = adj[i].y, b2 = adj[j].y;
		w1 = adj[i].wt, w2 = adj[j].wt;

		r1 = root(a1, 0); r2 = root(b1, 0);
		r3 = root(a2, 1); r4 = root(b2, 1);

		if (r1 != r2) {
			par1[r1] = r2;
			ans += w1;
		}
		if (r3 != r4) {
			par2[r3] = r4;
			ans += w2;
		}
	}
}
void CLEAR()
{
	ll i;
	rep(i, 0, ind) {
		adj[i].x = 0;
		adj[i].y = 0;
		adj[i].wt = 0;
	}
	rep(i, 0, n + 1) {
		par2[i] = 0;
		par1[i] = 0;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll i, j, t;
	scanf("%lld", &t);

	rep(i, 1, t + 1)
	{
		scanf("%lld", &n);
		ll a, b, c;
		ind = 0; ans = 0;
		rep(j, 0, n + 1) {
			par1[j] = -1;
			par2[j] = -1;
		}

		while (scanf("%lld%lld%lld", &a, &b, &c) != EOF)
		{
			if (a == 0 && b == 0 && c == 0) break;
			adj[ind].x = a;
			adj[ind].y = b;
			adj[ind].wt = c;
			ind++;
		}
		sort(adj, adj + ind, cmp);
		Kruskals();

		printf("Case %lld: ", i);
		
		if (ans & 1) printf("%lld/2\n", ans);
		else printf("%lld\n", ans / 2);

		CLEAR();

	}

	return 0;
}