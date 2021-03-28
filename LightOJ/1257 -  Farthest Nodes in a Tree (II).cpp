#include<bits/stdc++.h>
#define  MX      10005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

vector<PII> adj[3 * MX];
bool vis[3 * MX];
int n, m, mx_wt, st;
int dis1[3 * MX], dis2[3 * MX];

void dfs1(int nd, int wt)
{
   vis[nd] = 1;
   if (wt > mx_wt) {
      mx_wt = wt;
      st = nd;
   }
   for (auto ch : adj[nd])
      if (!vis[ch.first])
         dfs1(ch.first, wt + ch.second);
}
void bfs(int dis[], int nd)
{
   queue<PII> Q;
   Q.push({nd, 0});
   dis[nd] = 0;
   while (!Q.empty()) {
      auto cur = Q.front(); Q.pop();
      for (auto ch : adj[cur.first]) {
         if (dis[ch.first]==-1) {
            dis[ch.first] = dis[cur.first] + ch.second;
            Q.push({ch.first, dis[ch.first]});
         }
      }
   }
}
void RESET()
{
   for (int i = 0; i <= n; i++) {
      adj[i].clear();
      vis[i] = 0;
      dis1[i] = dis2[i] = -1;
   }
   mx_wt = 0;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

   memset(dis1, -1, sizeof(dis1));
   memset(dis2, -1, sizeof(dis2));

   int t; cin >> t;

   for (int k = 1; k <= t; k++) {
      int nd1, nd2;
      cin >> n;

      for (int i = 1; i < n; i++) {
         int x, y, wt;
         cin >> x >> y >> wt;
         adj[x].pb({y, wt});
         adj[y].pb({x, wt});
      }

      dfs1(0, 0);
      nd1 = st;

      for (int i = 0; i <= n; i++)
         vis[i] = 0;
      mx_wt = 0;

      dfs1(st, 0);
      nd2 = st;

      bfs(dis1, nd1);
      bfs(dis2, nd2);

      cout << "Case " << k << ":\n";
      for (int i = 0; i < n; i++)
         cout << (i == nd1 || i == nd2 ? mx_wt : max(dis1[i], dis2[i])) << "\n";

      RESET();
   }

   return 0;
}