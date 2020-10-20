#include<bits/stdc++.h>
#include <ext/rope>

#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))

#define count_one(a) __builtin_popcount(a)  // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i)    __builtin_parity(i)  //even parity 0 and odd parity 1
#define blz(a)       __builtin_clz(a) //Returns the number of leading zeroes in a number(a)
#define btz(a)       __builtin_ctz(a) //Returns the number of trailing zeroes in a number(a)
#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define PI   M_PI
#define endl "\n"
#define sc   scanf
#define pf   printf

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep1(i,n)       for(int i = 0; i < n; i++)
#define rep2(a,b)       for(int i = a; i <= b; i++)
#define rep3(a,b,c)     for(int i = a; i <= b; i+=c)
#define irep(a,b,c)     for(int i = b; i >=a; i-=c)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using namespace __gnu_cxx;

vector<ll> adj[100005];
bool vis[100005];
ll n, x, sum, cost[100005];

void DFS(ll nd)
{
	vis[nd] = true;

	for (auto y : adj[nd])
	{
		if (!vis[y])
		{
			DFS(y);
			cost[nd] += cost[y];
		}
	}

}
ll BFS(ll nd)
{
	vis[nd] = true;

	queue<int> Q;
	Q.push(nd);


	while (!Q.empty())
	{
		ll rt = Q.front();
		Q.pop();

		if (rt == 1 && adj[rt].size() < 2)
			return rt;
		else if (adj[rt].size() < 3 && rt != 1)
			return rt;
		for (auto it : adj[rt])
		{
			if (!vis[it])
			{
				Q.push(it);
				vis[it] = true;
			}
		}
	}
}
int main()
{
	IOS
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ll i, u, v, nd1, nd2;

	cin >> n >> x;

	for (i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}

	rep1(i, n - 1)
	{
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	nd1 = BFS(1);
	nd2 = n + 1;
	cost[nd2] = x;
	adj[nd1].pb(nd2);
	adj[nd2].pb(nd1);
	for (i = 1; i <= n + 1; i++)
		vis[i] = false;

	DFS(1);
	ll res = 0;

	for (i = 1; i <= n + 1; i++)
		res += cost[i];
	cout << res;

	return 0;
}
