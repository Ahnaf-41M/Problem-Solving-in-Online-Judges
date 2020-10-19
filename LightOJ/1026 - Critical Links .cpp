#include<bits/stdc++.h>

#define gcd(a,b)     __gcd(a,b)
#define lcm(a,b)     (a*(b/gcd(a,b)))

#define pb   push_back
#define endl "\n"

#define ll  long long
#define ull unsigned long long

#define W(t)            while(t--)
#define rep(i,n)      for(i = 0; i < n; i++)
#define repit(it,type)  for(auto it = type.begin(); it != type.end(); it++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<int> adj[100005];
vector<pair<int, int> > ans;
bool vis[100005];
int low[100005], disc[100005];
int n, m, timer;


void DFS(int nd, int par)
{
   vis[nd] = true;
   disc[nd] = low[nd] = ++timer;

   for (int x : adj[nd])
   {
      if (!vis[x])
      {
         DFS(x, nd);
         low[nd] = min(low[nd], low[x]);
         if (low[x] > disc[nd])
            ans.pb({min(x, nd), max(x, nd)});
      }
      else if (x != par)
         low[nd] = min(low[nd], disc[x]);
   }
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int i, j, t,k;
   scanf("%d", &t);

   for (k = 1; k <= t; k++)
   {
      timer = 0;
      scanf("%d",&n);

      rep(i, n)
      {
         int x, y, g;
         cin >> x;
         char c1, c2;

         cin >> c1 >> y >> c2;

         rep(j, y)
         {
            cin >> g;
            adj[x].pb(g);
         }
      }
      rep(i, n)
      {
         if (!vis[i])
         {
            timer = 0;
            DFS(i, -1);
         }
      }
      sort(ans.begin(), ans.end());
      cout << "Case " << k <<":\n"<< ans.size() << " critical links\n";
      rep(i, ans.size())
      {
         cout << ans[i].first << " - " << ans[i].second << endl;
      }
      ans.clear();
      rep(i, n) {
         vis[i] = false;
         adj[i].clear();
      }
   }

   return 0;
}