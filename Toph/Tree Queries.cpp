#include <bits/stdc++.h>
#include <ext/rope>

#define  pb   push_back
#define  int  long long
#define  endl "\n"
#define  MX   100005

#define  W(t)            while(t--)
#define  all(v)          v.begin(),v.end()
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  rep(i,a,b)      for(int i = a; i <= b; i++)
#define  irep(i,a,b)     for(int i = b; i >= a; i--)

using namespace std;
using namespace __gnu_cxx;

vector<int> adj[5 * MX], tree[5 * MX];
bool vis[5*MX];
int n, m, val[5 * MX];

void dfs(int node)
{
   vis[node] = true;
   tree[node].pb(val[node]);

   for (int ch : adj[node]) {
      if (!vis[ch]) {
         dfs(ch);
         for (int gg : tree[ch])
            tree[node].pb(gg);
      }
   }
   sort(all(tree[node]));
}
void solve()
{
   cin >> n >> m;
   rep(i, 1, n - 1) {
      int par;
      cin >> par;
      adj[par].pb(i + 1);
   }

   rep(i, 1, n) cin >> val[i];

   rep(i, 1, n) {
      if (!vis[i])
         dfs(i);
   }

   rep(i, 1, m) {
      int vrtx, x;
      cin >> vrtx >> x;
      int ans = lower_bound(all(tree[vrtx]), x) - tree[vrtx].begin();
      ans = tree[vrtx].size() - ans;
      cout << ans << endl;
   }
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   solve();

   return 0;
}