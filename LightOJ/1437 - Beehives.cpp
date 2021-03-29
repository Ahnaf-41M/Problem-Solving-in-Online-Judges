#include<bits/stdc++.h>
#define  MX      505
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

const int INF = 1e18;
vector<int> adj[MX];
int dis[MX], par[MX];
int n, m;

int bfs()
{
   int res = INF;

   for (int i = 0; i < n; i++) {
      queue<int> Q;
      Q.push(i);
      dis[i] = 0;

      while (!Q.empty()) {
         int nd = Q.front(); Q.pop();
         for (int ch : adj[nd]) {
            if (dis[ch] == INF) {
               dis[ch] = dis[nd] + 1;
               Q.push(ch);
               par[ch] = nd;
            }
            else if (nd != par[ch] && ch != par[nd])
               res = min(res, dis[nd] + dis[ch] + 1);
         }
      }
      for (int j = 0; j < n; j++)
         dis[j] = INF, par[j] = -1;
   }
   return res;
}
signed main()
{
   // ios::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);

   for (int i = 0; i < MX; i++)
      dis[i] = INF, par[i] = -1;

   int t; 
   scanf("%lld", &t);

   for (int k = 1; k <= t; k++) {
      scanf("%lld%lld", &n, &m);
      while (m--) {
         int x, y; scanf("%lld%lld", &x, &y);
         adj[x].pb(y), adj[y].pb(x);
      }

      int ans = bfs();

      printf("Case %lld: ", k);
      if (ans == INF)
         printf("impossible\n");
      else
         printf("%lld\n", ans);

      for (int i = 0; i < n; i++)
         adj[i].clear(), dis[i] = INF;
   }

   return 0;
}