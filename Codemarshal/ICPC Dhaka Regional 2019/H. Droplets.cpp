#include<bits/stdc++.h>
#define  MX      10005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

char s[105][105];
int n, m, res;
vector<int> adj[MX];
bool vis[MX];

void Make_Graph(vector<int> &v)
{
   int n2 = n - 1, m2 = m - 1;
   for (int i = 1; i <= n2; i++) {
      for (int j = 1; j <= m2; j++) {
         int x = (i - 1) * m2 + j;
         if (s[i][j] != 'R' && s[i][j] != 'B')
            if (i == 1)
               v.pb(j);

         if (i + 1 <= n2 && s[i + 1][j] != 'R' && s[i + 1][j] != 'B') {
            adj[x].pb(i * m2 + j);
            adj[i * m2 + j].pb(x);
         }
         if (j + 1 <= m2 && s[i][j + 1] != 'D' && s[i][j + 1] != 'B') {
            adj[x].pb(x + 1);
            adj[x + 1].pb(x);
         }
      }
   }
}
void dfs(int nd)
{
   vis[nd] = 1;
   res++;
   for (int ch : adj[nd])
      if (!vis[ch])
         dfs(ch);
}
void RESET()
{
   for (int i = 1; i <= n * m; i++) {
      adj[i].clear();
      vis[i] = 0;
   }
   res = 0;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int t; cin >> t;
   for (int k = 1; k <= t; k++) {
      vector<int> v;

      cin >> n >> m;
      for (int i = 1; i <= n; i++)
         for (int j = 1; j <= m; j++)
            cin >> s[i][j];

      Make_Graph(v);

      for (int x : v)
         if (!vis[x])
            dfs(x);

      cout << "Case " << k << ": " << res << endl;

      RESET();
   }
   return 0;
}