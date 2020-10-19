/*
You have to find the 'second shortest path' here. First, think what will be the second shortest
path between two adjactent nodes.
1. You can visit the minimum weight edge multiple times.
2. You can visit the edge which has the second minimum weight
Say, you have the following input:
2 3
1 2 50
1 2 120
1 2 160
The shortest path between 1 and 2 is 50. The second shortest path? You can go back to 1 and
return to 2 using the (1 2 50) edge, so it will cost 50 + 2*50 = 150 (option 1). Or you can
use the second minimum weight edge (1 2 120), which will cost 120 (option 2). Take the minimum
of these two, you will get the result.
In my code I've extended this idea for multiple nodes. In Dijkstra's algorithm,
we calculate shortest path from every node from the source node. In my code, I have done the
same, the array 'dis1' stores the shortest path of a node from the source node. Besides,
I also calculated second shortest path for every node and stored the result in 'dis2' array.
The array 'min_dis' stores (2*minimum weight edge) for every node (to use for option 1).
*/
#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)          while(t--)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 6000
#define pii pair<int,int>
#define INF 1999999999

vector<pii> adj[mx];
int dis1[mx], n, m, dis2[mx], min_dis[mx];
bool back[mx];

void Dijkstra(int nd)
{
	/* find the minimum weight edge which lies with node i */
	for (int i = 1; i <= n; i++)
		for (auto ch : adj[i])
			min_dis[i] = min(min_dis[i], 2 * ch.second);

	priority_queue<pii, vector<pii>, greater<pii> > Q;

	Q.push({0, nd});
	dis1[nd] = 0;

	while (!Q.empty())
	{
		int tp = Q.top().second;
		int wt = Q.top().first;

		Q.pop();
		if (dis2[tp] < wt)
			continue;

		for (auto ch : adj[tp])
		{
			int cur_nd = ch.first;
			int cur_wt = ch.second;

			if (dis1[cur_nd] > cur_wt + wt)
			{
				Q.push({cur_wt + wt, cur_nd});
				dis2[cur_nd] = dis1[cur_nd];
				dis1[cur_nd] = cur_wt + wt;
			}
			else if (dis2[cur_nd] > cur_wt + wt && dis1[cur_nd] != cur_wt + wt)
			{
				dis2[cur_nd] = cur_wt + wt;
				Q.push({dis2[cur_nd], cur_nd});
			}
		}
		/* If we haven't check the option 1 yet (go back along with
		   the minimum edge and return) then do it now */
		if (!back[tp])
		{
			Q.push({min_dis[tp] + dis1[tp], tp});
			back[tp] = true;
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
	int tc; cin >> tc;

	for (int k = 1; k <= tc; k++)
	{
		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			dis1[i] = INF;
			dis2[i] = INF;
			min_dis[i] = INF;
		}
		W(m)
		{
			int x, y, w; cin >> x >> y >> w;
			adj[x].pb({y, w});
			adj[y].pb({x, w});
		}
		Dijkstra(1);
		cout << "Case " << k << ": " << dis2[n] << endl;
		for (int i = 1; i <= n; i++) {
			back[i] = false;
			adj[i].clear();
		}

	}

	return 0;
}