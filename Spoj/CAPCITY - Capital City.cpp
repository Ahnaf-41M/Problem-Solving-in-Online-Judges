#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 200000

vector<int> adj[mx], SCC[mx];
int low[mx], disc[mx], n, m, num;
bool vis[mx];
stack<int> S;

void tarjan(int nd)
{
	static int Timer = 0;
	vis[nd] = true;
	disc[nd] = low[nd] = ++Timer;
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
	if (disc[nd] == low[nd])
	{
		while (true)
		{
			int tp = S.top(); S.pop();
			SCC[num].pb(tp);
			vis[tp] = false;
			if (tp == nd)
				break;
		}
		num++;
	}
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;

	W(m)
	{
		int x, y; cin >> x >> y;
		adj[x].pb(y);
	}
	for (int i = 1; i <= n; i++)
		if (!disc[i])
			tarjan(i);
	vector<int> ans;
	for (int i = 0; i < num; i++)
		if (SCC[i].size() > ans.size())
			ans = SCC[i];
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}