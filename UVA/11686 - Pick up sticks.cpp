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

vector<int> adj[100005], ans;
bool ok;
int n, m, parent[100005], color[100005];

void DFS(int nd, int par)
{
	color[nd] = 1;

	for (auto ch : adj[nd])
	{
		if (!color[ch])
			DFS(ch, nd);
		else if (color[ch] == 1)
		{
			ok = false;
			return;
		}

	}
	if (!ok)
		return;

	color[nd] = 2;
	ans.pb(nd);

}

int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m, n)
	{
		int x, y, i;
		ok = true;

		rep(i, m) {
			cin >> x >> y;
			adj[x].pb(y);
		}

		for (i = 1; i <= n; i++)
			if (!color[i])
				DFS(i, 0);

		if (ok)
		{
			reverse(ans.begin(), ans.end());
			rep(i, ans.size()) cout << ans[i] << endl;
		}
		else
			cout << "IMPOSSIBLE\n";

		for (i = 1; i <= n; i++)
		{
			adj[i].clear();
			color[i] = 0;
		}
		ans.clear();
	}

	return 0;
}