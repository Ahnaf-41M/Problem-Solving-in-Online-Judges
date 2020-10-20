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

vector<int> adj[10005];
vector<int> ID;
int val[100005];

int injured, killed, n, m, ind;
bool vis[100005];


void DFS(int nd)
{
	
	if (val[nd] > killed)
	{
		killed = val[nd];
		ind = nd;
	}
	else if (val[nd] == killed && ind > nd)
	{
		ind = nd;
	}
	vis[nd] = true;
	for (int j = 0; j < adj[nd].size(); j++)
	{
		if (!vis[adj[nd][j]])
			DFS(adj[nd][j]);
	}
}
int main()
{
	IOS
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i, x, y;

	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		cin >> val[i];
		injured += val[i];
	}
	W(m)
	{
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	ll ans = 0;
	for (i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			killed = -1;
			DFS(i);
			ID.pb(ind);
			ans += killed;
		}

	}
	cout << ans << " " << injured - ans << endl;
	sort(ID.begin(), ID.end());
	for (i = 0; i < ID.size(); i++)
		cout << ID[i] << " ";

	return 0;
}
