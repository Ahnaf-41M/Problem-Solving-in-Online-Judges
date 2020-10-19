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

int n, a[120][120];
bool vis[120];
vector<int> adj[120];

void DFS(int nd, int x)
{
	if (nd == x)
		return;
	vis[nd] = true;

	for (auto it : adj[nd])
		if (!vis[it])
			DFS(it, x);
}
int main()
{
	IOS
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;

	cin >> t;

	for (int k = 1; k <= t; k++)
	{
		cin >> n;

		int i, j;

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				cin >> a[i][j];

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (a[i][j] == 1)
					adj[i].pb(j);

		char ans[n][n];
		bool reachable[120] = {};

		DFS(0, -1);

		for (i = 0; i < n; i++)
			reachable[i] = vis[i];

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				vis[j] = false;

			DFS(0, i);
			for (j = 0; j < n; j++)
				if (!vis[j] && reachable[j])
					ans[i][j] = 'Y';
				else
					ans[i][j] = 'N';
		}


		/*Output*/
		string s = "";
		cout << "Case " << k << ":\n";
		cout << "+";
		s += "+";
		for (i = 1; i <= 2 * n - 1; i++)
		{
			cout << "-"; s += "-";
		}
		s += "+";
		cout << "+" << endl;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (j == 0)
					cout << "|";
				cout << ans[i][j] << "|";
			}
			cout << endl;
			cout << s << endl;
		}
		
		for(i = 0; i < n; i++)
			adj[i].clear();
		for(i = 0; i < n; i++)
			vis[i] = false;

	}

	return 0;
}
