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

vector<int> adj[100005];
int n, m, cnt, ans, tot, white;
int color[100005];
bool ok = true;

void BFS(int nd)
{
	color[nd] = 0;

	queue<int> Q;
	Q.push(nd);
	white = 0; tot = 0;

	while (!Q.empty())
	{
		int fr = Q.front();
		Q.pop();

		if (color[fr] == 0)
			white++;

		tot++;
		for (auto x : adj[fr])
		{
			if (color[x] == -1)
			{
				color[x] = 1 - color[fr];
				Q.push(x);
			}
			else if (color[x] == color[fr])
				ok = false;
		}


		if (!ok)
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

	int t;
	memset(color, -1, sizeof(color));

	cin >> t;
	W(t)
	{
		cin >> n >> m;
		ok = true;

		int x, y, i;
		ans = 0;

		W(m)
		{
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		rep(i, n)
		{
			if (color[i] == -1)
			{
				BFS(i);
				if (tot == 1) ans++;
				else ans += min(white, tot - white);

			}
			if (!ok)
				break;

		}
		if (!ok)
			cout << -1 << endl;
		else
			cout << ans << endl;
		rep(i, n) {
			color[i] = -1;
			adj[i].clear();
		}

	}

	return 0;
}