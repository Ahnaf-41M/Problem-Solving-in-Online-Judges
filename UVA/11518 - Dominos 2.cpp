#include<bits/stdc++.h>
#define  MX      10005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int n, m, l, cnt;
vector<int> adj[MX];
bool vis[MX];
void dfs(int nd)
{
   cnt++;
   vis[nd] = 1;
   for (int ch : adj[nd])
      if (!vis[ch])
         dfs(ch);
}
signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int t;

   cin >> t;

   while ( t-- ) {
      cin >> n >> m >> l;

      for (int i = 1; i <= n; i++)
         adj[i].clear(), vis[i] = 0;

      while (m--) {
         int x, y;
         cin >> x >> y;
         adj[x].pb(y);
      }
      while (l--) {
         int x; cin >> x;
         dfs(x);
      }

      cnt = 0;
      for (int i = 1; i <= n; i++)
         cnt += vis[i];
      cout << cnt << endl;
   }

   return 0;
}