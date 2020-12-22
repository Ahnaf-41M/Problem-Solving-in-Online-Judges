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

int n, k, stNode,stNode2;
vector<int> adj[105];
bool vis[105];
int SIZE[105];

void dfs(int nd)
{
   vis[nd] = true;
   for (int ch : adj[nd])
      if (!vis[ch])
         dfs(ch);
}
int isEulerian()
{
   int odd = 0;
   rep(i, 1, n) {
      if (SIZE[i]) {
         dfs(i);
         stNode2 = i;
         break;
      }
   }
   rep(i, 1, n) {
      if (!vis[i] && SIZE[i])
         return 0;
      if (SIZE[i] & 1) {
         if (!stNode)
            stNode = i;
         stNode = min(stNode, i);
         odd++;
      }
   }
   if (odd > 2)
      return 0;
   return 1;
}
void solve()
{
   cin >> n >> k;

   W(k) {
      int s, d, m;
      cin >> s >> d >> m;
      adj[s].pb(d);
      adj[d].pb(s);
      SIZE[s] += m;
      SIZE[d] += m;
   }

   int ok = isEulerian();

   if (ok) {
      cout << "YES " << (stNode ? stNode : stNode2) << "\n";
   }
   else
      cout << "NO\n";
   return;
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int t;
   cin >> t;

   W(t) {
      solve();
      rep(i, 1, n) {
         vis[i] = false;
         adj[i].clear();
         SIZE[i] = 0;
      }
      stNode = 0;
   }

   return 0;
}