#include<bits/stdc++.h>

#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(a,b,c)      for(int i = a; i < b; i+=c)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;


vector<int> adj[10005], ans;
bool vis[110];

void DFS(int rt)
{
	vis[rt] = true;

	for (auto x : adj[rt])
		if (!vis[x])
			DFS(x);
	ans.pb(rt);
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;

	while (cin >> n >> m, n)
	{
		int x, y, i, j;

		W(m)
		{
			cin >> x >> y;
			adj[x].pb(y);
		}
		for (i = 1; i <= n; i++)
			if (!vis[i])
				DFS(i);
		for (i = ans.size() - 1; i >= 0; i--)
			cout << ans[i] << " ";
		cout << endl;
		ans.clear();
		for (i = 1; i <= n; i++)
			vis[i] = false;
	}

	return 0;
}