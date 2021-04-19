#include <bits/stdc++.h>
#include <ext/rope>

#define  pb            push_back
#define  int           long long
#define  endl          "\n"
#define  MX            100005

#define  all(v)        v.begin(),v.end()
#define  gcd(a,b)      __gcd(a,b)
#define  lcm(a,b)      (a*b)/gcd(a,b)
#define  rep(i,a,b)    for(int i = a; i <= b; i++)
#define  irep(i,b,a)   for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

vector<int> adj[2 * MX], vtx;
bool vis[2 * MX];
int n, m;

void dfs(int nd)
{
   vis[nd] = true;
   for (int ch : adj[nd])
      if (!vis[ch])
         dfs(ch);
}
void Solve()
{
   cin >> n >> m;

   rep(i, 1, m) {
      int u, v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
   }
   rep(i, 1, n) if (!vis[i]) {
      vtx.pb(i);
      dfs(i);
   }

   vector<pair<int, int>> ans;
   rep(i, 0, vtx.size() - 1) {
      if (i + 1 < vtx.size())
         ans.pb({vtx[i], vtx[i + 1]});
   }

   cout << ans.size() << endl;
   for (auto it : ans)
      cout << it.first << " " << it.second << endl;
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   //int T;
   //cin >> T;

   //while (T--)
   Solve();

   return 0;
}