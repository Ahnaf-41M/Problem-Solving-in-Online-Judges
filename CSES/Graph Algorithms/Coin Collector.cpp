/*We just need to make condensation graph(adj2 in this case) 
  and run a dfs in that graph and each time take the max cost 
  of all childs of a particular node and add this cost to the node. */
#include <bits/stdc++.h>
using namespace std;
#define  MX  100005
#define  int long long int

vector<int> adj[MX + 5], revAdj[MX + 5], adj2[MX + 5];
int n, m, k, ans, cur, cost[MX], sccCost[MX], scc[MX];
bool vis[MX + 5];
stack<int> S;
map<pair<int, int>, int> done;

void dfs1(int nd)
{
   vis[nd] = true;

   for (int ch : adj[nd])
      if (!vis[ch])
         dfs1(ch);
   S.push(nd);
}

void dfs2(int nd)
{
   vis[nd] = true;
   cur += cost[nd]; //calculating the cost of that SCC
   scc[nd] = k;    //assigning SCC number
   for (int ch : revAdj[nd])
      if (!vis[ch])
         dfs2(ch);
}
void Make_Condensation_graph()
{
   for (int i = 1; i <= n; i++) {
      for (int ch : adj[i]) {
         int x = scc[i];
         int y = scc[ch]; 
         if (x != y && !done[ {x, y}]) { //add an edge if they are not from same SCC
            done[ {x, y}]++;
            adj2[x].push_back(y);
         }
      }
   }
}
void dfs3(int nd)
{
   int ndMX = 0; //max value of all childs of that node
   vis[nd] = 1;
   for (int ch : adj2[nd]) {
      if (!vis[ch])
         dfs3(ch);
      ndMX = max(ndMX, sccCost[ch]);
   }
   sccCost[nd] += ndMX;
}
signed main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> n >> m;

   for (int i = 1; i <= n; i++)
      cin >> cost[i];
   while (m--) {
      int x, y; cin >> x >> y;
      adj[x].push_back(y);
      revAdj[y].push_back(x);
   }

   for (int i = 1; i <= n; i++)
      if (!vis[i])
         dfs1(i);
   memset(vis, false, sizeof(vis));

   while (!S.empty()) {
      int tp = S.top(); S.pop();
      if (!vis[tp]) {
         k++;
         dfs2(tp);
         sccCost[k] = cur;
         cur = 0;
      }
   }

   Make_Condensation_graph();

   memset(vis, 0, sizeof(vis));
   for (int i = 1; i <= k; i++)
      if (!vis[i])
         dfs3(i);
   int ans = 0;
   for (int i = 1; i <= k; i++)
      ans = max(ans, sccCost[i]);
   cout << ans << endl;
}