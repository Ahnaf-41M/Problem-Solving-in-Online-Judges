#include<bits/stdc++.h>

#define endl "\n"
#define pb   push_back
#define ll   long long
#define MX 100005
#define ff first
#define ss second
#define pii pair<int,int>

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
using namespace std;


int mnLCA[MX][20], mxLCA[MX][20], ANCS[MX][20];
int n, par[MX], ev[MX], level[MX];
vector<pii> adj[MX];
bool vis[MX];
const int inf = 1e9;

void DFS(int nd, int p)
{
	vis[nd] = true;
	par[nd] = p;

	for (auto ch : adj[nd]) {
		if (!vis[ch.ff]) {
			ev[ch.ff] = ch.ss;
			level[ch.ff] = level[nd] + 1;
			DFS(ch.ff, nd);
		}
	}
}
void init()
{
	int i, j;
	int sz = log2(n);

	rep(j, 0, sz + 1) {
		rep(i, 1, n + 1) {
			mnLCA[i][j] = inf;
			mxLCA[i][j] = -inf;
			ANCS[i][j] = -1;
		}
	}

	rep(i, 1, n + 1) {
		ANCS[i][0] = par[i];
		mxLCA[i][0] = ev[i];
		mnLCA[i][0] = ev[i];
	}
}

void buildLCA()
{
	int i, j;
	int sz = log2(n);

	rep(j, 1, sz + 1) {
		rep(i, 1, n + 1) {
			if (ANCS[i][j - 1] != -1) {

				int p = ANCS[i][j - 1];
				ANCS[i][j] = ANCS[p][j - 1];
				mxLCA[i][j] = max(mxLCA[i][j - 1], mxLCA[p][j - 1]);
				mnLCA[i][j] = min(mnLCA[i][j - 1], mnLCA[p][j - 1]);

			}
		}
	}
}
pii Query(int x, int y)
{
	int i, j, mn = inf, mx = 0;
	int sz = log2(n);

	if (level[x] > level[y]) swap(x, y);
	int d = level[y] - level[x];

	while (d > 0)
	{
		int k = log2(d);

		mn = min(mnLCA[y][k], mn);
		mx = max(mxLCA[y][k], mx);

		y = ANCS[y][k];
		d -= (1 << k);
	}
	// cout<<mn<<" "<<mx<<" "<<x<<" "<<y<<endl;
	if (x == y) return {mn, mx};

	for (j = sz; j >= 0; j--) {
		if (ANCS[x][j] != ANCS[y][j]) {
			mn = min(min(mnLCA[x][j], mnLCA[y][j]), mn);
			mx = max(max(mxLCA[x][j], mxLCA[y][j]), mx);
			x = ANCS[x][j];
			y = ANCS[y][j];
		}
	}

	mn = min(min(mnLCA[x][0], mnLCA[y][0]), mn);
	mx = max(max(mxLCA[x][0], mxLCA[y][0]), mx);
	return {mn, mx};
}
void RESET()
{
	int i, j;
	int sz = log2(n);

	rep(i, 1, n + 1) {
		par[i] = 0; ev[i] = 0; level[i] = 0;
		adj[i].clear();
		vis[i] = false;
		rep(j, 0, sz + 1) {
			mxLCA[i][j] = -inf;
			mnLCA[i][j] = inf;
		}
	}
}
int main()
{
	int i, j, k, t; scanf("%d", &t);

	rep(k, 1, t + 1)
	{
		scanf("%d", &n);

		rep(i, 0, n - 1) {
			int x, y, w; scanf("%d%d%d", &x, &y, &w);
			adj[x].pb({y, w});
			adj[y].pb({x, w});
		}

		DFS(1, -1);
		init();
		buildLCA();

		printf("Case %d:\n", k);

		int q; scanf("%d", &q);

		W(q)
		{
			int x, y; scanf("%d%d", &x, &y);
			auto ans = Query(x, y);
			printf("%d %d\n", ans.ff, ans.ss);
		}

		RESET();

	}
	return 0;
}

/*
2

6
3 6 50
2 5 30
2 4 300
1 2 100
1 3 200
4
1 4
4 6
2 5
3 5

2
1 2 100
1
1 2
*/