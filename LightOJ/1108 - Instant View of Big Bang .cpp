/*1. Make a graph by reverse the edge direction.
  2. Run Bellman Ford in reverse Graph and check if there exist a negative weight cycle.
  Reversing edge doesn’t affect in cycle because if we reverse the edge 
  direction then cycle remain unchanged.
  3. If exist a negative cycle then run a DFS on the reverse graph 
  for finding the nodes which are reachable from negative cycle and 
  store them in a vector and after sorting the vector print them.
  4. If there is no negative cycle then print impossible.*/
#include<bits/stdc++.h>
#define pb      push_back
#define ll      long long
#define MX      2005
#define inf     10000

#define W(t)            while(t--)
#define all(v)          v.begin(),v.end()
#define rep(i,a,b)      for(i = a; i < b; i++)
using namespace std;

struct Graph
{
   ll x, y, w;
};

Graph adj[MX];
ll dis[MX], n, m, par[MX];
bool vis[MX];
vector<ll> revAdj[MX];

void dfs(ll nd, ll p)
{
   vis[nd] = true;
   for (ll ch : revAdj[nd])
      if (!vis[ch])
         dfs(ch, nd);
}
void Bellman_Ford()
{
   ll i, j;
   // dis[n-1] = 0;

   rep(i, 0, n - 1) {
      rep(j, 0, m) {
         ll u = adj[j].x;
         ll v = adj[j].y;
         ll wt = adj[j].w;

         if (dis[v] > dis[u] + wt)
            dis[v] = dis[u] + wt;
      }
   }

   bool cycle = false;

   rep(j, 0, m) {
      ll u = adj[j].x;
      ll v = adj[j].y;
      ll wt = adj[j].w;

      if (dis[v] > dis[u] + wt) {
         cycle = true;
         dis[v] = dis[u] + wt;
         if (!vis[u])
            dfs(u, -1);
      }
   }

   if (cycle) {
      rep(i, 0, n) {
         if (vis[i])
            printf(" %d", i);
      }
   }
   else
      printf(" impossible");
}
void RESET()
{
   ll i;

   rep(i, 0, 1001) {
      revAdj[i].clear();
      vis[i] = false;
      dis[i] = inf;
   }
   rep(i, 0, 2001) {
      adj[i].x = 0;
      adj[i].y = 0;
      adj[i].w = 0;
   }
}
int main()
{
   ll i, j, t;

   scanf("%lld", &t);

   for (ll k = 1;  k <= t; k++)
   {
      scanf("%lld%lld", &n, &m);
      
      RESET();
      rep(i, 0, m) {
         ll a, b, c; scanf("%lld%lld%lld", &b, &a, &c);
         adj[i].x = a; adj[i].y = b;
         adj[i].w = c;
         revAdj[a].pb(b);
      }
      printf("Case %lld:", k);
      Bellman_Ford();
      printf("\n");
   }
}