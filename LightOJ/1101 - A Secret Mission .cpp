#include<bits/stdc++.h>

#define endl "\n"
#define pb   push_back
#define ll   long long
#define MX   50010
#define ff   first
#define ss   second
#define inf  1000000000

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
using namespace std;

struct Graph
{
	int x, y, wt;
};

Graph adj[100005];
vector<pair<int, int> > MST[MX];
int n, m, par[MX], lev[MX];
bool vis[MX];
pair<int, int> LCA[MX][20];

bool cmp(Graph a, Graph b)
{
	return a.wt < b.wt;
}
void init()
{
	int i, j;
	int sz = log2(n);

	rep(j, 0, sz + 1) {
		rep(i, 1, n + 1) {
			LCA[i][j].ff = -1;
			LCA[i][j].ss = -1;
		}
	}
}
int find(int k)
{
	if (par[k] < 0) return k;
	else return par[k] = find(par[k]);
}
void Kruskals()
{
	int i, j;
	rep(i, 0, m) {
		int a, b, c, r1, r2;
		a = adj[i].x; b = adj[i].y;
		c = adj[i].wt;
		r1 = find(a); r2 = find(b);

		if (r1 != r2) {
			par[r1] = r2;
			MST[a].pb({b, c});
			MST[b].pb({a, c});
		}
	}
}
void dfs(int nd, int p)
{
	vis[nd] = true;
	LCA[nd][0].ff = p;

	for (auto ch : MST[nd]) {
		if (!vis[ch.ff]) {
			lev[ch.ff] = lev[nd] + 1;
			LCA[ch.ff][0].ss = ch.ss;
			dfs(ch.ff, nd);
		}
	}
}
void buildLCA()
{
	int i, j;
	int sz = log2(n);

	rep(j, 1, sz + 1) {
		rep(i, 1, n + 1) {
			if (LCA[i][j - 1].ff != -1) {
				int p = LCA[i][j - 1].ff;
				LCA[i][j].ff = LCA[p][j - 1].ff;
				LCA[i][j].ss = max(LCA[p][j - 1].ss,LCA[i][j-1].ss);
			}
		}
	}
}
int Query(int a, int b)
{
	int ans = 0;

	if (lev[a] > lev[b]) swap(a, b);
	int d = lev[b] - lev[a];

	while (d > 0) {
		int k = log2(d);
		ans = max(ans, LCA[b][k].ss);
		b = LCA[b][k].ff;
		d -= (1 << k);
	}
	if (a == b) return ans;

	int sz = log2(n);
	for (int j = sz; j >= 0; j--) {
		if (LCA[a][j].ff != LCA[b][j].ff) {
			ans = max(ans, max(LCA[a][j].ss, LCA[b][j].ss));
			a = LCA[a][j].ff; b = LCA[b][j].ff;
		}
	}
	ans = max(ans,max(LCA[a][0].ss,LCA[b][0].ss));
	return ans;
}
void RESET()
{
	int i, j;
	int sz = log2(n);

	rep(i, 1, n + 1) {
		vis[i] = false; par[i] = 0;
		lev[i] = 0;
		MST[i].clear();
		rep(j, 0, sz + 1) {
			LCA[i][j].ff = 0;
			LCA[i][j].ss = 0;
		}
	}
}
int main()
{
	int t, i, j, k; scanf("%d", &t);

	rep(k, 1, t + 1)
	{
		scanf("%d%d", &n, &m);
		rep(i, 1, n + 1) par[i] = -1;

		rep(i, 0, m) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			adj[i].x = u; adj[i].y = v;
			adj[i].wt = w;
		}

		init();
		sort(adj, adj + m, cmp);
		Kruskals();
		dfs(1, -1);
		buildLCA();

		printf("Case %d:\n", k);

		int q; scanf("%d", &q);
		W(q)
		{
			int a, b; scanf("%d%d", &a, &b);
			printf("%d\n", Query(a, b));
		}
		RESET();
	}
	return 0;
}