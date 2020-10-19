#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define pb push_back
#define endl "\n"

vector<int> adj[mx], nodes;
set<int> St;
int nc, level[mx];
bool vis[mx];
map<int,int> mp;

int BFS(int nd, int TTL)
{
	vis[nd] = true;
	queue<int> Q;
	Q.push(nd);
	level[nd] = 0;

	while (!Q.empty())
	{
		int fr = Q.front(); Q.pop();

		for (int ch : adj[fr])
		{
			if (!vis[ch])
			{
				vis[ch] = true;
				Q.push(ch);
				level[ch] = level[fr] + 1;
			}
		}
	}
	int cnt = 0;

	for (auto it : St)
		if (level[mp[it]] > TTL)
			cnt++;
	return cnt;
}

void CLEAR()
{
	for (auto it : St) {
		vis[mp[it]] = false;
		level[mp[it]] = INT_MAX;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t = 1;
	while (cin >> nc, nc)
	{
		string s;
		vector<int> tc;
		int ind = 1;

		cin.ignore();
		while (true)
		{
			getline(cin, s);
			stringstream ss(s);
			int val;

			while (ss >> val)
				nodes.pb(val);
			if (nodes.size() == nc * 2)
				break;
		}
		for (int i = 0; i < nodes.size(); i += 2) {
			if(!mp[nodes[i]]) mp[nodes[i]] = ind++;
			if(!mp[nodes[i+1]]) mp[nodes[i+1]] = ind++;
			int u = mp[nodes[i]];
			int v = mp[nodes[i+1]];
			adj[u].pb(v);
			adj[v].pb(u);
			St.insert(nodes[i]);
			St.insert(nodes[i + 1]);
			level[u] = INT_MAX;
			level[v] = INT_MAX;
		}
		while (true) {
			getline(cin, s);
			stringstream ss(s);
			int val;

			while (ss >> val)
				tc.pb(val);
			if (tc[tc.size() - 1] == 0 && tc[tc.size() - 2] == 0)
				break;
		}
		for (int i = 0; i < tc.size(); i += 2)
		{
			if (tc[i]||tc[i+1])
				cout << "Case " << t++ << ": " << BFS(mp[tc[i]], tc[i + 1]) << " nodes not reachable from node " << tc[i] << " with TTL = " << tc[i + 1] << "." << endl;
			CLEAR();
		}
		for (int i = 0; i < nodes.size(); i++)
			adj[mp[nodes[i]]].clear();
		nodes.clear();
		St.clear();
		mp.clear();

	}
}