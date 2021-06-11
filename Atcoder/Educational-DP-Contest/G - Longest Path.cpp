#include "bits/stdc++.h"
#define  MX         100005
#define  ff         first
#define  ss         second
#define  pb         push_back
#define  int        long long
#define  PII        pair<int,int>
#define  all(v)     v.begin(),v.end()
#define  rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

vector<int> adj[MX];
int dp[MX];
int n, m;

void dfs(int nd)
{
   dp[nd] = 0;
   for (int ch : adj[nd]) {
      if (dp[ch] == -1) {
         dfs(ch);
      }
      dp[nd] = max(dp[nd], dp[ch] + 1);
   }
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   memset(dp, -1, sizeof(dp));
   cin >> n >> m;

   rep(i, 1, m) {
      int x, y; cin >> x >> y;
      adj[x].pb(y);
   }
   for (int i = 1; i <= n; i++) {
      if (dp[i] == -1) {
         dp[i] = 0;
         dfs(i);
      }
   }
   int ans = 0;
   rep(i, 1, n) ans = max(ans, dp[i]);
   cout << ans;
   return 0;
}