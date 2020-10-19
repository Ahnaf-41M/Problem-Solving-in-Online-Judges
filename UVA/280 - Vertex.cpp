#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 200

vector<int> adj[mx], ans;
bool vis[mx];
int n, test;

void dfs(int x)
{
	for (int ch : adj[x])
		if (!vis[ch])
			vis[ch] = true, dfs(ch);
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while (cin >> n, n)
	{
		string s;
		cin.ignore();

		while (true)
		{
			getline(cin, s);
			if (s[0] == '0')
				break;

			stringstream ss(s);
			vector<int> nodes;
			int k;

			while (ss >> k) nodes.pb(k);
			for (int i = 1; i < nodes.size(); i++)
				if (nodes[i])
					adj[nodes[0]].pb(nodes[i]);
		}
		cin >> test;
		W(test)
		{
			int x; cin >> x;
			dfs(x);
			for (int i = 1; i <= n; i++)
			{
				if (!vis[i])
					ans.pb(i);
				vis[i] = false;
			}
			cout << ans.size();
			if (ans.size()) cout << " ";
			for (int i = 0; i < ans.size(); i++)
			{
				cout << ans[i];
				if (i != ans.size() - 1)
					cout << " ";
			}
			ans.clear();
			cout << endl;
		}
		for (int i = 1; i <= n; i++)
			adj[i].clear();

	}

	return 0;
}