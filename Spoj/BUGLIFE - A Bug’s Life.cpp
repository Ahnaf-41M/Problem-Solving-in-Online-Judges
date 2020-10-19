#include<bits/stdc++.h>

#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(i,n)        for(i = 0; i < n; i++)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 1000000

vector<int> adj[mx + 5];
int n, m, color[mx + 5];
bool vis[mx + 5], bug;

void bfs(int nd)
{
	queue<int> Q;
	Q.push(nd);
	color[nd] = 1;

	while (!Q.empty())
	{
		int fr = Q.front();
		Q.pop();

		for (int ch : adj[fr]) {
			if (color[ch] == -1) {
				color[ch] = 1 - color[fr];
				Q.push(ch);
			}
			else if (color[ch] == color[fr]) {
				bug = true;
				break;
			}
		}
		if (bug)
			break;
	}
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, i, j = 0;

	cin >> t;
	memset(color, -1, sizeof(color));

	W(t)
	{
		cin >> n >> m;
		bug = false;
		W(m)
		{
			int u, v; cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		for(i = 1; i <= n; i++)
			if(color[i] == -1)
				bfs(i);
		cout << "Scenario #" << ++j << ":\n";
		if (bug)
			cout << "Suspicious bugs found!\n";
		else
			cout << "No suspicious bugs found!\n";

		for (i = 1; i <= n; i++) {
			color[i] = -1;
			adj[i].clear();
		}
	}

	return 0;
}