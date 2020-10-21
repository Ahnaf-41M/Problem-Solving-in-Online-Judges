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
bool vis[MX];
int n, m, k, reached[MX];

void dfs(int nd)
{
   reached[nd]++;
   vis[nd] = true;

   for (int ch : adj[nd])
      if (!vis[ch])
         dfs(ch);
}
void RESET()
{
   int i;
   rep(i, 1, n + 1) {
      vis[i] = false;
      adj[i].clear();
      reached[i] = 0;
   }
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   int t, k,cs, i;
   scanf("%d", &t);

   rep(cs, 1, t + 1)
   {
      scanf("%d%d%d", &k, &n, &m);
      vector<int> persons;

      rep(i, 0, k) {
         int x; scanf("%d", &x);
         persons.pb(x);
      }
      W(m) {
         int x, y; scanf("%d%d", &x, &y);
         adj[x].pb(y);
      }
      rep(i, 0, persons.size()) {
         ZERO(vis);
         dfs(persons[i]);
      }
      int ans = 0;
      rep(i, 1, n + 1) {
         if (reached[i] == k) {
            ans++;
         }
      }

      printf("Case %d: %d\n", cs, ans);
      RESET();
   }
}