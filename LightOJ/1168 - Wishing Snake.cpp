#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define  ff      first
#define  ss      second
#define  pb      push_back
#define  ll      long long
#define  MX      1005
#define  inf     1000000
#define  mod     1000000007
#define  endl    "\n"

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*(b/gcd(a,b)))
#define  all(v)          v.begin(),v.end()
#define  ZERO(a)         memset(a,0,sizeof(a))
#define  MINUS(a)        memset(a,-1,sizeof(a))
#define  rep(i,a,b)      for(i = a; i < b; i++)
#define  IOS             ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

vector<int> adj[MX];
int cnt, scc[MX], disc[MX], low[MX], Timer;
bool vis[MX];
stack<int> S;
int out_deg[MX];

void tarjanSCC(int nd)
{
   S.push(nd);
   vis[nd] = true;
   low[nd] = disc[nd] = ++Timer;

   for (int ch : adj[nd]) {
      if (!disc[ch]) {
         tarjanSCC(ch);
         low[nd] = min(low[nd], low[ch]);
      }
      else if (vis[ch])
         low[nd] = min(low[nd], disc[ch]);
   }

   if (low[nd] == disc[nd])
   {
      cnt++;
      int cur = -1;

      while ( cur != nd )
      {
         cur = S.top();
         S.pop();
         vis[cur] = false;
         scc[cur] = cnt;
      }
   }
}
void dfs(int nd)
{
   vis[nd] = true;
   for (int ch : adj[nd]) {
      if (scc[ch] != scc[nd])
         out_deg[scc[nd]]++;
      if (!vis[ch])
         dfs(ch);
   }
}
void RESET()
{
   int i;
   rep(i, 0, 1001) {
      vis[i] = false;
      adj[i].clear(); scc[i] = 0;
      out_deg[i] = low[i] = disc[i] = 0;
   }
   Timer = 0; cnt = 0;
   while (!S.empty()) S.pop();
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   int t, n, k, cs;
   scanf("%d", &t);

   rep(cs, 1, t + 1)
   {
      scanf("%d", &n);
      vector<int> nodes;
      W(n)
      {
         scanf("%d", &k);
         W(k)
         {
            int x, y; scanf("%d%d", &x, &y);
            adj[x].pb(y); nodes.pb(x);
         }
      }

      tarjanSCC(0);
      ZERO(vis);
      dfs(0);

      bool ok = true;
      int i;
      
      rep(i, 0, nodes.size()) {
         if (out_deg[scc[nodes[i]]] > 1 || !vis[nodes[i]]) {
            ok = false;
            break;
         }
      }
      if (ok)
         printf("Case %d: YES\n", cs);
      else
         printf("Case %d: NO\n", cs);
      RESET();
   }
}