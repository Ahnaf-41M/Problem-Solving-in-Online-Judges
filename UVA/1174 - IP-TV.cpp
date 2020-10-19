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
#define PII pair<int,int>

vector<PII> adj[mx];
bool vis[mx];
int n, m, minCost;

void prims(int nd)
{
	priority_queue<PII, vector<PII>, greater<PII> > Q;
	Q.push({0, nd});

	while (!Q.empty())
	{
		auto p = Q.top(); Q.pop();

		nd = p.second;
		minCost += p.first;
		vis[nd] = true;

		for (auto ch : adj[nd])
			if (!vis[ch.second])
				Q.push(ch);
	}
}

void CLEAR()
{
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		vis[i] = false;
	}
	minCost = 0;
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;

	cin >> t;
	W(t)
	{
		int node = 1, mn = INT_MAX, st;
		cin >> n >> m;
		map<string, int> mp;
		W(m)
		{
			string s1, s2; int w;
			cin >> s1 >> s2 >> w;
			if (!mp[s1]) mp[s1] = node++;
			if (!mp[s2]) mp[s2] = node++;

			adj[mp[s1]].pb({w, mp[s2]});
			adj[mp[s2]].pb({w, mp[s1]});
			if (mn > w) {
				mn = w; st = mp[s1];
			}
		}
		prims(st);
		cout << minCost << endl;

		CLEAR();
	}

	return 0;
}