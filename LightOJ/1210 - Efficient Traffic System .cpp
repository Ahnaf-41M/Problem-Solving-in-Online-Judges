#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 20005

bool in_deg[mx], out_deg[mx], vis[mx];
vector<int> adj[mx], revAdj[mx];
int scc, n, m, idx[mx];
stack<int> S;

void dfs1(int nd)
{
	vis[nd] = true;

	for (int ch : adj[nd]) {
		if (!vis[ch]) {
			dfs1(ch);
		}
	}
	S.push(nd);
}
void dfs2(int nd)
{
	idx[nd] = scc;
	for (int ch : revAdj[nd]) {
		if (!idx[ch]) {
			dfs2(ch);
		}
	}
}
void KosaRaju()
{
	int i, j;
	rep(j, 1, n + 1) 
		if (!vis[j]) 
			dfs1(j);
		
	scc = 0;
	while (!S.empty()) {
		int tp = S.top();
		S.pop();

		if (idx[tp]) continue;
		scc++;
		dfs2(tp);
	}
}
void RESET()
{
	int i;
	rep(i, 1, n + 1) {
		adj[i].clear(); revAdj[i].clear();
		in_deg[i] = false; out_deg[i] = false;
		idx[i] = 0; vis[i] = false;
	}
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i, t, j;
	cin >> t;

	rep(i, 1, t + 1)
	{
		RESET();
		cin >> n >> m;
		W(m) {
			int x, y; cin >> x >> y;
			adj[x].pb(y); revAdj[y].pb(x);
		}
		KosaRaju();
		if (scc == 1) {
			cout << "Case " << i << ": " << 0 << endl;
			continue;
		}
		rep(j, 1, n + 1) {
			for (auto ch : adj[j]) {
				if (idx[j] != idx[ch]) {
					out_deg[idx[j]] = true;
					in_deg[idx[ch]] = true;
				}
			}
		}
		int in = 0, out = 0;
		rep(j, 1, scc + 1) {
			if (!out_deg[j]) out++;
			if (!in_deg[j]) in++;
		}
		cout << "Case " << i << ": " << max(in, out) << endl;
	}

	return 0;
}