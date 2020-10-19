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
#define mx 100005

vector<int> adj[mx];
int n, m, low[mx], disc[mx], timer, scc;
stack<int> S;
bool vis[mx];

void tarjan(int nd)
{
	vis[nd] = true;
	disc[nd] = low[nd] = ++timer;
	S.push(nd);

	for (int ch : adj[nd])
	{
		if (!disc[ch])
		{
			tarjan(ch);
			low[nd] = min(low[nd], low[ch]);
		}
		else if (vis[ch])
			low[nd] = min(low[nd], disc[ch]);
	}

	if (low[nd] == disc[nd])
	{
		while (true)
		{
			int tp = S.top(); S.pop();
			vis[tp] = false;
			if (tp == nd)
				break;
		}
		scc++;
	}
}
void CLEAR()
{
	for (int i = 1; i <= n; i++) {
		vis[i] = false;
		adj[i].clear();
		low[i] = disc[i] = 0;
	}
	timer = 0;
	scc = 0;
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while (cin >> n >> m, n)
	{
		string s, s2;
		map<string, int> mp;
		int ind = 1, i;

		cin.ignore();
		rep(i, n) {
			getline(cin, s);
			mp[s] = ind++;
		}
		m;

		W(m)
		{
			getline(cin, s);
			getline(cin, s2);
			adj[mp[s]].pb(mp[s2]);
		}
		for (i = 1; i <= n; i++)
			if (!disc[i])
				tarjan(i);
		cout<<scc<<endl;
		CLEAR();

	}

	return 0;
}