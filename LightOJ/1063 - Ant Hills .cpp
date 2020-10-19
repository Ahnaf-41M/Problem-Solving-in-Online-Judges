#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 20000

int low[mx], disc[mx], n, m, Timer, cnt,AP[mx];
bool vis[mx];
vector<int> adj[mx];
map<pair<int, int>, int> mp;

void find_artipoints(int nd, int par)
{
	vis[nd] = true;
	disc[nd] = low[nd] = ++Timer;
	int child = 0;

	for (int ch : adj[nd]) {
		if (!disc[ch]) {
			child++;
			find_artipoints(ch, nd);
			low[nd] = min(low[nd], low[ch]);

			if (par==-1 && child > 1)
				AP[nd] = 1;
			if(par!=-1 && low[ch] >= disc[nd])
				AP[nd] = 1;
		}
		else if (ch != par) {
			low[nd] = min(low[nd], disc[ch]);
		}
	}
}
void RESET()
{
	int i;
	rep(i, 1, n + 1) {
		vis[i] = false;
		adj[i].clear();
		low[i] = 0;
		disc[i] = 0;
		AP[i] = 0;
	}
	Timer = 0; cnt = 0;
}
int main()
{
	IOS
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, k, i; cin >> t;

	rep(k, 1, t + 1)
	{
		cin >> n >> m;

		W(m)
		{
			int x, y; cin >> x >> y;
			//if (!mp[ {x, y}])
				adj[x].pb(y); adj[y].pb(x);
			//mp[ {x, y}]++; mp[ {y, x}]++;
		}
		find_artipoints(1, -1);
		rep(i,1,n+1){
			if(AP[i]){
				cnt++;
			}
		}
		cout << "Case " << k << ": " << cnt << endl;
		RESET();
	}

	return 0;
}