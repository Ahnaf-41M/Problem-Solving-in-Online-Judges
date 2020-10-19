/*We just need to find the max length of a cycle and which node started
  this cycle.*/
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

vector<int> adj[100005];
bool vis[100005];
int cycle_len[100005];

int DFS(int rt)
{
	vis[rt] = true;
	int cc = 0;
	for (auto id : adj[rt])
		if (!vis[id])
			cc = DFS(id) + 1;
	vis[rt] = false;
	return cycle_len[rt] = cc;

}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, i, j, n, x, y;

	cin >> t;

	for (i = 1; i <= t; i++)
	{
		cin >> n;

		for (j = 0; j < n; j++)
		{
			cin >> x >> y;
			adj[x].pb(y);
		}
		int len = 0, node;
		for (j = 1; j <= n; j++)
		{
			if (!cycle_len[j])
				DFS(j);
			if (cycle_len[j] > len)
			{
				len = cycle_len[j];
				node = j;
			}

		}

		cout << "Case " << i << ": " << node << endl;
		for (j = 1; j <= n; j++)
		{
			vis[j] = false;
			adj[j].clear();
			cycle_len[j] = 0;
		}
	}

	return 0;
}