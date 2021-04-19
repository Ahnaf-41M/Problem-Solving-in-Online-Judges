#include <bits/stdc++.h>
using namespace std;
#define  MX  100005

vector<int> adj[MX + 5], revAdj[MX + 5];
int n, m, k, ans[MX];
bool vis[MX + 5];
stack<int> S;

void dfs1(int nd)
{
   vis[nd] = true;

   for (int ch : adj[nd])
      if (!vis[ch])
         dfs1(ch);
   S.push(nd);
}

void dfs2(int nd)
{
   vis[nd] = true;
   ans[nd] = k;
   for (int ch : revAdj[nd])
      if (!vis[ch])
         dfs2(ch);
}
int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   cin >> n >> m;
   while (m--) {
      int x, y; cin >> x >> y;
      adj[x].push_back(y);
      revAdj[y].push_back(x);
   }

   for (int i = 1; i <= n; i++)
      if (!vis[i])
         dfs1(i);
   memset(vis, false, sizeof(vis));

   while (!S.empty()) {
      int tp = S.top(); S.pop();
      if (!vis[tp]) {
         k++;
         dfs2(tp);
      }
   }

   cout << k << endl;
   for (int i = 1; i <= n; i++)
      cout << ans[i] << " ";
}