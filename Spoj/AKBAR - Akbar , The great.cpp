#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           1000005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

vector<int> adj[MX];
int N, R, M;
int parent[MX], ok = 1;
int city_num, strength;
void dfs(int nd, int cur_str)
{
	if (parent[nd] && parent[nd] != city_num) ok = 0;
	parent[nd] = city_num;
	if (!ok || cur_str == 0) return;

	for (int ch : adj[nd])
		dfs(ch, cur_str - 1);
}
void Solve(int tc)
{
	cin >> N >> R >> M;
	while (R--) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	while (M--) {
		cin >> city_num >> strength;
		dfs(city_num, strength);
	}
	rep(i, 1, N) if (!parent[i]) ok = 0;

	cout << (ok ? "Yes\n" : "No\n");

	rep(i, 1, N) {
		adj[i].clear();
		parent[i] = 0;
	}
	ok = 1;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		Solve(tc);
	}

	return 0;
}