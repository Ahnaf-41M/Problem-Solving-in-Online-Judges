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

ll a[100005], ans = 0, mn;
vector<ll> adj[100005];
bool vis[100005];

void DFS(int nd)
{
	vis[nd] = true;
	mn = min(mn, a[nd]);

	for (auto x : adj[nd])
		if (!vis[x])
			DFS(x);
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, k, i;

	cin >> n >> k;
	rep(1, n + 1, 1) cin >> a[i];

	W(k)
	{
		ll x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	rep(1, n + 1, 1)
	{
		mn = INT_MAX;
		if (!vis[i])
		{
			DFS(i);
			ans += mn;
		}
	}
	cout << ans << endl;
}