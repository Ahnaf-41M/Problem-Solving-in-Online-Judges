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
#define mx 105

vector<int> adj[mx], ans[mx];
int n, m, timer, scc;
map<string, int> mp;
map<int, string> name;
string s1, s2;
bool vis[mx];
int low[mx], disc[mx];
stack<int> St;

void Tarjan(int nd)
{
	vis[nd] = true;
	low[nd] = disc[nd] = ++timer;
	St.push(nd);

	for (int ch : adj[nd])
	{
		if (!disc[ch])
		{
			Tarjan(ch);
			low[nd] = min(low[nd], low[ch]);
		}
		else if (vis[ch])
			low[nd] = min(low[nd], disc[ch]);
	}
	if (low[nd] == disc[nd])
	{
		while (true)
		{
			int tp = St.top(); St.pop();
			vis[tp] = false;
			ans[scc].pb(tp);
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
		ans[i].clear();
		low[i] = 0; disc[i] = 0;
	}
	scc = 0;
	timer = 0;
	mp.clear();
	name.clear();
	while (!St.empty()) St.pop();
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 0, i, j;

	while (cin >> n >> m && (n || m))
	{
		int ind = 1;
		timer = 0;
		rep(i, m)
		{
			cin >> s1 >> s2;
			if (!mp[s1]) {
				mp[s1] = ind;
				name[ind++] = s1;
			}
			if (!mp[s2]) {
				mp[s2] = ind;
				name[ind++] = s2;
			}
			adj[mp[s1]].pb(mp[s2]);
		}
		cout << "Calling circles for data set " << ++t << ":\n";

		for (i = 1; i <= n; i++)
			if (!disc[i])
				Tarjan(i);

		for (i = 0; i < scc; i++)
		{
			for (j = 0; j < ans[i].size() - 1; j++)
			{
				cout << name[ans[i][j]] << ", ";
			}
			cout << name[ans[i].back()] << endl;
		}
		cout << endl;
		CLEAR();
	}

	return 0;
}