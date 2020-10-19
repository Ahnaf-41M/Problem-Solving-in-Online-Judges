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
int n, m, color[mx], CC;
bool ok = true;

void dfs(int nd, int par)
{
	color[nd] = 1;
	for (int ch : adj[nd])
	{
		if (!color[ch])
			dfs(ch, nd);
		else if (color[ch] == 1 && ch != par)
		{
			ok = false;
			break;
		}
	}
	if (!ok)
		return;
	color[nd] = 2;
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	int ed = m;
	ok = true;
	CC = 0;

	W(m)
	{
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!color[i]) {
			dfs(i, 0);
			CC++;
		}
	}
	if (ok && CC == 1 && ed == n - 1)
		cout << "YES\n";
	else
		cout << "NO\n";


	return 0;
}