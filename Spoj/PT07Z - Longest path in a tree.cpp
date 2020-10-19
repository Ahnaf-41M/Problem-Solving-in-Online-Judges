#include<bits/stdc++.h>

#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 10010

vector<int> adj[mx];
bool vis[mx];
int n, cur, cnt, st;

void dfs(int nd, int d)
{
	vis[nd] = true;
	if (cur < d) {
		cur = d;
		st = nd;
	}
	for (int ch : adj[nd])
		if (!vis[ch])
			dfs(ch, d + 1);
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i;
	cin >> n;

	rep(i, n) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1, 0);
	cur = 0;
	for (int i = 1; i <= n; i++)
		vis[i] = false;
	dfs(st, 0);
	cout << cur << endl;


	return 0;
}