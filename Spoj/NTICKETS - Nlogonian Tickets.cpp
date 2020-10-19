#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long
#define ff first
#define ss second

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define MX 100010

pair<int, int> LCA[MX][30];
int n, q, ans, sq, level[MX];
vector<pair<int, int> > adj[MX];

void init()
{
   int i, j;
   sq = log2(n);

   rep(i, 0, n + 1)
   {
      rep(j, 0, sq)
      {
         LCA[i][j].ff = -1;
         LCA[i][j].ss = 0;
      }
   }
}
void dfs(int nd, int par, int wt)
{
   LCA[nd][0].ff = par;
   LCA[nd][0].ss = wt;

   for (auto ch : adj[nd])
   {
      if (ch.ff != par)
      {
         level[ch.ff] = level[nd] + 1;
         dfs(ch.ff, nd, ch.ss);
      }
   }
}
void buildLCA()
{
   for (int j = 1; j <= sq; j++)
   {
      for (int i = 1; i <= n; i++)
      {
         if (LCA[i][j - 1].ff != -1)
         {
            int par = LCA[i][j - 1].ff;
            LCA[i][j].ff = LCA[par][j - 1].ff;
            LCA[i][j].ss = max(LCA[i][j - 1].ss, LCA[par][j - 1].ss);
         }
      }
   }
}
int Query(int a, int b)
{
   if (level[a] > level[b])
      swap(a, b);
   int d = level[b] - level[a];

   while (d > 0)
   {
      int i = log2(d);
      ans = max(ans, LCA[b][i].ss);
      b = LCA[b][i].ff;
      d -= (1 << i);
   }
   if (a == b)
      return ans;
   int ans2 = 0;
   for (int j = sq; j >= 0; j--)
   {
      if (LCA[a][j].ff != -1 && LCA[a][j].ff != LCA[b][j].ff)
      {
         int tmp = max(LCA[a][j].ss, LCA[b][j].ss);
         ans2 = max(tmp, ans2);
         a = LCA[a][j].ff;
         b = LCA[b][j].ff;
      }
   }
   int tmp = max(LCA[a][0].ss, LCA[b][0].ss);
   ans2 = max(tmp, ans2);
   return max(ans, ans2);

}
int main()
{
   IOS
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   while (cin >> n, n)
   {
      int i, j;
      init();
      rep(i, 1, n)
      {
         int x, y, w;
         cin >> x >> y >> w;
         adj[x].pb({y, w});
         adj[y].pb({x, w});
      }
      dfs(1, -1, 0);
      buildLCA();
      cin >> q;

      W(q)
      {
         int a, b;
         cin >> a >> b;
         cout << Query(a, b) << endl;
         ans = 0;
      }

      rep(i, 0, n + 1) {
         level[i] = 0;
         adj[i].clear();
         rep(j, 0, sq + 1) {
            LCA[i][j].ff = 0;
            LCA[i][j].ss = 0;
         }
      }
   }


   return 0;
}
