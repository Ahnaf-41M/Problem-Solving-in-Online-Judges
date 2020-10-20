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

vector<int> adj[500];
int t, n, cnt;
int a[30][30];
bool vis[30][30];
int dx[] = {0, 0, -1, 1};
int dy[] = { -1, 1, 0, 0};

bool valid(int u, int v)
{
	if (u >= 1 && u <= n && v >= 1 && v <= n)
		return true;
	return false;
}
void DFS(int x, int y)
{
	vis[x][y] = true;

	for (int i = 0; i < 4; i++ )
	{
		int u = x + dx[i];
		int v = y + dy[i];

		if (valid(u, v) && !vis[u][v] && a[u][v] == 0)
		{
			if(u==n && v==n)
				cnt++;
			DFS(u,v);
		}
	}
	vis[x][y] = false;
}
int main()
{
	IOS
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;

	W(t)
	{
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		int i, j;
		bool ok = true;
		cnt = 0;

		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				cin >> a[i][j];
		if (a[1][1] == 1 && a[n][n] == 1)
			ok = false;
			if (!ok)
		{
			cout << 0 << endl;
			continue;
		}
	DFS(1, 1);
	cout << cnt << endl;
}
}
