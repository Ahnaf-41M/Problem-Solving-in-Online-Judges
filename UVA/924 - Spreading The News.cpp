#include<bits/stdc++.h>
using namespace std;
#define mx 3000

vector<int> adj[mx];
bool vis[mx];
int E, level[mx], tc;

pair<int, int> bfs(int nd)
{
	int maxx = 0,day=0;
	map<int, int> freq;
	vis[nd] = true;
	queue<int> Q;
	Q.push(nd);

	while (!Q.empty())
	{
		int fr = Q.front(); Q.pop();
		for (int ch : adj[fr])
		{
			if (!vis[ch])
			{
				level[ch] = level[fr] + 1;
				vis[ch] = true;
				Q.push(ch);
			}
		}
	}
	for (int i = 0; i < E; i++)
		if (level[i])
			freq[level[i]]++;

	for (auto it = freq.begin(); it != freq.end(); it++){
		if(it->second > maxx){
			maxx = it->second;
			day = it->first;
		}
	}
	return {maxx, day};

}
void RESET()
{
	for (int i = 0; i < E; i++) {
		vis[i] = false;
		level[i] = 0;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int i, j; cin >> E;

	for (i = 0; i < E; i++)
	{
		int nodes; cin >> nodes;
		while (nodes--)
		{
			int x; cin >> x;
			adj[i].push_back(x);
		}
	}
	cin >> tc;

	while (tc--)
	{
		int nd; cin >> nd;
		pair<int, int> ans = bfs(nd);
		if (ans.first != 0 && ans.second != 0)
			cout << ans.first << " " << ans.second << endl;
		else
			cout << 0 << endl;
		RESET();
	}

}