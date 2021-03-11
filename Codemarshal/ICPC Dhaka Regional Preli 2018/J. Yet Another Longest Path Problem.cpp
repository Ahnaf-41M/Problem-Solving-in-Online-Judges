#include<bits/stdc++.h>
#define  MX      100005
#define  pb      push_back
#define  ff      first
#define  ss      second
#define  int     long long
#define  all(v)  v.begin(),v.end()
using namespace std;

vector<int> adj[MX];
vector<pair<int, int>> ans;

void dfs(int nd, int par, int lev = 0)
{
   if (lev) {
      if (lev & 1)
         ans.pb({nd, par});
      else
         ans.pb({par, nd});
   }
   for (int ch : adj[nd])
      if (ch != par)
         dfs(ch, nd, lev + 1);
}
signed main()
{
   //ios::sync_with_stdio(false);
   //cin.tie(NULL);
   //cout.tie(NULL);
   int T;
   scanf("%lld", &T);

   for (int k = 1; k <= T; ++k) {
      int n;
      scanf("%lld", &n);

      for (int i = 1; i <= n; i++)
         adj[i].clear();
      ans.clear();

      for (int i = 1; i <= n - 1; i++) {
         int x, y; scanf("%lld%lld", &x, &y);
         adj[x].pb(y);
         adj[y].pb(x);
      }

      dfs(1, -1);
      printf("Case %lld:\n", k);
      for (auto it : ans)
         printf("%lld %lld\n", it.first, it.second);

   }

   return 0;
}