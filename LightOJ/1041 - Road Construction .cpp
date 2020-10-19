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
	int x, y, wt;
};

int par[105], n, ind, ans;
Graph adj[55];

bool cmp(Graph a, Graph b)
{
	return a.wt < b.wt;
}
int root(int v)
{
	if (par[v] < 0) return v;
	else return par[v] = root(par[v]);
}
void Kruskals()
{
	int i, j;
	rep(i, 0, n)
	{
		int a, b, cost, r1, r2;
		a = adj[i].x; b = adj[i].y;
		cost = adj[i].wt;

		r1 = root(a); r2 = root(b);

		if (r1 != r2)
		{
			par[r1] = r2;
			ans += cost;
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i, j, t, k;

	scanf("%d", &t);

	rep(k, 1, t + 1)
	{
		string city1, city2;
		int cost, cnt = 0;
		map<string, int> mp;

		scanf("%d", &n);
		ind = 0; ans = 0;

		rep(i, 0, n)
		{
			cin >> city1 >> city2 >> cost;
			if (!mp[city1]) mp[city1] = ++ind;
			if (!mp[city2]) mp[city2] = ++ind;

			adj[i].x = mp[city1];
			adj[i].y = mp[city2];
			adj[i].wt = cost;
		}

		rep(i, 1, ind + 1) par[i] = -1;
		sort(adj, adj + n, cmp);
		Kruskals();

		rep(i, 0, n) {
			adj[i].x = 0;
			adj[i].y = 0;
			adj[i].wt = 0;
		}
		rep(i, 1, ind + 1) {
			if (par[i] < 0) {
				cnt++;
			}
		}

		if (cnt > 1)
			printf("Case %d: Impossible\n", k);
		else
			printf("Case %d: %d\n", k, ans);
		rep(i, 1, ind + 1) par[i] = 0;

	}

	return 0;
}