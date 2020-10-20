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

vector<int> adj[1000];
char s[35][35];
int start, ed, n;
int cost[2000], vis[2000];

void BFS(int st)
{
	vis[st] = true;
	memset(cost, -1, sizeof(cost));
	cost[st] = 0;

	queue<int> Q;
	Q.push(st);

	while (!Q.empty())
	{
		int fr = Q.front();
		Q.pop();

		for (int x : adj[fr])
		{
			if (!vis[x])
			{
				vis[x] = true;
				Q.push(x);
				cost[x] = cost[fr] + 1;
			}
		}

	}
}
int main()
{
	IOS
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == 'S')
				start = i * n + j;
			if (s[i][j] == 'S' && (s[i + 1][j] == 'P' || s[i + 1][j] == 'E') && i + 1 < n)
			{
				adj[i * n + j].pb((i + 1)*n + j);
				adj[(i + 1)*n + j].pb(i * n + j);
			}
			if (s[i][j] == 'S' && (s[i][j + 1] == 'P' || s[i][j + 1] == 'E') && j + 1 < n)
			{
				adj[i * n + j].pb(i * n + j + 1);
				adj[i * n + j + 1].pb(i * n + j);
			}

			if (i + 1 < n && s[i][j] == 'P' && (s[i + 1][j] == 'P' || s[i + 1][j] == 'E' || s[i + 1][j] == 'S'))
			{
				adj[i * n + j].pb((i + 1)*n + j);
				adj[(i + 1)*n + j].pb(i * n + j);
			}
			if (s[i][j] == 'P' && j + 1 < n && (s[i][j + 1] == 'P' || s[i][j + 1] == 'E' || s[i][j + 1] == 'S'))
			{
				adj[i * n + j].pb(i * n + j + 1);
				adj[i * n + j + 1].pb(i * n + j);
			}
			if (s[i][j] == 'E')
				ed = i * n + j;
			if (s[i][j] == 'E' && (s[i + 1][j] == 'P' || s[i + 1][j] == 'S') && i + 1 < n)
			{
				adj[i * n + j].pb((i + 1)*n + j);
				adj[(i + 1)*n + j].pb(i * n + j);
			}
			if (s[i][j] == 'E' && (s[i][j + 1] == 'S' || s[i][j + 1] == 'P') && j + 1 < n)
			{
				adj[i * n + j].pb(i * n + j + 1);
				adj[i * n + j + 1].pb(i * n + j);
			}


		}
	}
	BFS(start);

	cout << cost[ed] << endl;
	return 0;
}
