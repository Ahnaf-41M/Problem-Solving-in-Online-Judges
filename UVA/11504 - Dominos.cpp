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
#define pii pair<int,int>
#define mx 100005

bool vis[mx];
int n, m, t, ans;
vector<int> adj[mx], tps;

void dfs(int nd)
{
	vis[nd] = true;
	for(int ch : adj[nd])
		if(!vis[ch])
			dfs(ch);
	tps.pb(nd);
}
void CLEAR()
{
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		vis[i] = false;
	}
	tps.clear();
	ans = 0;
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> t;

	W(t)
	{
		cin >> n >> m;
		int x, y, i;

		W(m)
		{
			cin >> x >> y;
			adj[x].pb(y);
		}
		for (i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i);

        for(i = 1; i <= n; i++)
        	vis[i] = false;
		for (i = tps.size()-1; i >= 0; i--)
			if (!vis[tps[i]])
				{
					dfs(tps[i]);
					ans++;
				}
		cout << ans << endl;
		CLEAR();
	}
}