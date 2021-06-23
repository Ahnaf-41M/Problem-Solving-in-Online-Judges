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

vector<int> adj[MX];
pair<int, int> parDis[MX];
int n, m;

void bfs()
{
   queue<int> Q;
   Q.push(1);
   parDis[1].ss = 0;

   while (!Q.empty()) {
      int nd = Q.front();
      Q.pop();
      for (int ch : adj[nd]) {
         if (parDis[ch].ss == -1) {
            parDis[ch].ff = nd;
            parDis[ch].ss = parDis[nd].ss + 1;
            Q.push(ch);
         }
      }
   }
}
void Solve(int tc)
{
   memset(parDis, -1, sizeof(parDis));
   cin >> n >> m;
   while (m--) {
      int x, y;
      cin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
   }
   bfs();
   if (parDis[n].ss == -1) cout << "IMPOSSIBLE";
   else {
      vector<int> path;
      int cur = n;
      while (cur != -1)
         path.pb(cur), cur = parDis[cur].ff;
      reverse(all(path));

      cout << parDis[n].ss + 1 << "\n";
      for (int x : path) cout << x << " ";
   }
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int T = 1;
   //cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}