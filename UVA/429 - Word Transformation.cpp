#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl "\n"
#define mx 100005

vector<int> adj[mx];
int level[mx], len;
bool vis[mx];
vector<string> words;
map<string, int> mp;

int bfs(int st, int ed)
{
	vis[st] = true;
	queue<int>  Q;
	Q.push(st);

	while (!Q.empty())
	{
		int fr = Q.front(); Q.pop();
		for (int ch : adj[fr])
		{
			if (!vis[ch])
			{
				vis[ch] = true;
				level[ch] = level[fr] + 1;
				Q.push(ch);
			}
		}
	}
	return level[ed];
}
void reset()
{
	for (int i = 1; i <= len; i++) {
		level[i] = 0;
		vis[i] = false;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t; cin >> t;

	while (t--)
	{
		string s;
		len = 0;

		while (cin >> s)
		{
			if (s[0] == '*') break;
			words.pb(s);
		}
		for (int i = 0; i < words.size(); i++)
			mp[words[i]] = ++len;
		for (int i = 0; i < words.size(); i++)
		{
			for (int j = i + 1; j < words.size(); j++)
			{
				string ts1 = words[i], ts2 = words[j];
				if (ts1.size() == ts2.size())
				{
					int cnt = 0;
					map<int, int> ff;

					for (int g = 0; g < ts1.size(); g++)
					{
						for (int h = 0; h < ts2.size(); h++)
						{
							if (ts2[h] == ts1[g] && !ff[g] && !ff[h])
							{
								ff[g]++; ff[h]++; cnt += 2; break;
							}
						}
					}
					if (cnt == 2 * ts2.size() - 2) {
						adj[mp[ts1]].pb(mp[ts2]);
						adj[mp[ts2]].pb(mp[ts1]);
					}
				}

			}
		}

		cin.ignore();
		while (true)
		{
			string s1;
			getline(cin, s1);
			if (s1.size() == 0) break;

			stringstream ss(s1);
			vector<string> tmp;
			string s2;

			while (ss >> s2)
				tmp.pb(s2);
			cout << tmp[0] << " " << tmp[1] << " " << bfs(mp[tmp[0]], mp[tmp[1]]) << endl;
			reset();
		}
		//cout<<adj[1].size()<<endl;
		for (int i = 1; i <= len; i++)
			adj[i].clear();
		words.clear();
		mp.clear();
		if (t) cout << endl;

	}
}
