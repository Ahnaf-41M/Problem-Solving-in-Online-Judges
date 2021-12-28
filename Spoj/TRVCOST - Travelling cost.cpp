#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

vector<PII> adj[505];
int n, U, q, dis[505];

void Dijkstra(int nd)
{
   dis[nd] = 0;
   priority_queue<PII, vector<PII>, greater<PII> > Q;
   Q.push({0, nd});

   while (!Q.empty()) {
      nd = Q.top().ss;
      Q.pop();

      for (auto ch : adj[nd]) {
         if (dis[ch.ff] > dis[nd] + ch.ss) {
            dis[ch.ff] = dis[nd] + ch.ss;
            Q.push({dis[ch.ff], ch.ff});
         }
      }
   }
}
void Solve(int tc)
{
   fill(dis, dis + 505, 1e15);
   cin >> n;
   rep(i, 1, n) {
      int x, y, w; cin >> x >> y >> w;
      adj[x].pb({y, w});
      adj[y].pb({x, w});
   }
   cin >> U;
   Dijkstra(U);
   cin >> q;

   while (q--) {
      int V; cin >> V;
      if (dis[V] == 1e15) cout << "NO PATH\n";
      else cout << dis[V] << "\n";
   }

}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   int T = 1;
   //cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}