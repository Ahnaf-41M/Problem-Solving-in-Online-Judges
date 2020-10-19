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

vector<int> adj[100005];
int color[100005];
int nodes;
bool ok;

void BFS(int nd)
{
	color[nd] = 0;

	queue<int> Q;
	Q.push(nd);

	while(!Q.empty())
	{
		int fr = Q.front();
		Q.pop();

		for(auto x: adj[fr])
		{
			if(color[x] == -1)
			{
				color[x] = 1-color[fr];
				Q.push(x);
			}
			else if(color[x] == color[fr])
				ok = false;
		}
		if(!ok)
			break;
	}
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(color,-1,sizeof(color));
	while (cin >> nodes, nodes)
	{
		int x, y;
		ok = true;

		while (cin >> x >> y, x)
		{
			adj[x].pb(y);
			adj[y].pb(x);
		}
		for (int i = 1; i <= nodes; i++)
			if (color[i] == -1)
				BFS(i);
		if(!ok)
			cout<<"NO\n";
		else
			cout<<"YES\n";
		for(int i = 1; i <= nodes; i++)
		{
			adj[i].clear();
			color[i] = -1;
		}

	}

	return 0;
}