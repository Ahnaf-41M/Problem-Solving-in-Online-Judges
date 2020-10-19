#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long
#define INF  1000000000

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define pii pair<int,int>

vector<pii> adj[110];
int dis[110], n, m, w;

void Dijkstra(int nd)
{
    dis[nd] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > Q;

    Q.push({0, nd});

    while (!Q.empty())
    {
        int node = Q.top().second;
        Q.pop();

        for (auto ch : adj[node])
        {
            if (dis[node] + ch.second < dis[ch.first])
            {
                dis[ch.first] = dis[node] + ch.second;
                Q.push({dis[ch.first], ch.first});
            }
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

    for (int k = 1;  k <= tc; k++)
    {
        cin >> n >> m;
        W(m)
        {
            int u, v, wt; cin >> u >> v >> wt;
            adj[u].pb({v, wt});
            adj[v].pb({u, wt});
        }
        for(int i = 1; i <= n; i++) 
            dis[i] = INF;
        Dijkstra(1);
        if (dis[n] == INF)
            printf("Case %d: Impossible\n", k);
        else
            printf("Case %d: %d\n", k, dis[n]);
        for (int i = 1; i <= n; i++)
            adj[i].clear();

    }
}