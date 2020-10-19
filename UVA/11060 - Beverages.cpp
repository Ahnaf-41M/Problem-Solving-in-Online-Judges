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

vector<int> adj[10005], ans;
int indeg[105];
int n, m;

void Kahn()
{
	priority_queue<int,vector<int>,greater<int>> Q;

	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0)
			Q.push(i);
	while (!Q.empty())
	{
		int fr = Q.top();

		ans.pb(fr);
		Q.pop();

		for (auto x : adj[fr])
		{
			indeg[x]--;
			if (indeg[x] == 0)
				Q.push(x);
		}
	}
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	while (cin >> n)
	{
		string s1, s2;
		vector<string> drinks;
		int i, j, k = 1;
		map<string, int> mp;
		memset(indeg, 0, sizeof(indeg));
		ans.clear();

		rep(i, n) {
			cin >> s1;
			drinks.pb(s1);
			mp[s1] = k; k++;
		}
		cin >> m;

		rep(i, m) {
			cin >> s1 >> s2;
			adj[mp[s1]].pb(mp[s2]);
			indeg[mp[s2]]++;
		}
		Kahn();
		cout << "Case #" << t << ": Dilbert should drink beverages in this order: ";
		rep(i, ans.size())
		{
			if (i) cout << " ";
			cout << drinks[ans[i] - 1];
		}
		cout << "." << endl<<endl;
		t++;
		for (i = 1; i <= n; i++)
			adj[i].clear();

	}

	return 0;
}