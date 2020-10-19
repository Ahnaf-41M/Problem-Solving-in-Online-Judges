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
#define mx 200010

vector<int> adj[mx];
int color[mx], n, m;
bool cycle;

void bfs(int nd)
{
	color[nd] = 1;
	queue<int> Q;
	Q.push(nd);

	while(!Q.empty())
	{
		int fr = Q.front();
		Q.pop();

		for(int ch : adj[fr])
		{
			if(color[ch] == -1)
			{
				Q.push(ch);
				color[ch] = 1 - color[fr];
			}
			else if(color[ch] == color[fr])
			{
				cycle = true;
				break;
			}
		}
		if(cycle)
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
	int x, y;
	memset(color, -1, sizeof(color));
	vector<pair<int, int> > edges;

	cin >> n >> m;
	W(m)
	{
		cin >> x >> y;
		edges.pb({x, y});
		adj[x].pb(y);
		adj[y].pb(x);
	}
	bfs(edges[0].first);
	if(cycle)
		cout<<"NO\n";
	else
	{
		int a[n+5] = {};
		cout<<"YES\n";
		for(int i = 0; i < edges.size(); i++)
		{
			if(!a[edges[i].first]){
				cout<<color[edges[i].first];
				a[edges[i].first]++;
			}
			else{
				cout<<color[edges[i].second];
				a[edges[i].second]++;
			}

		}
			
	}


	return 0;
}