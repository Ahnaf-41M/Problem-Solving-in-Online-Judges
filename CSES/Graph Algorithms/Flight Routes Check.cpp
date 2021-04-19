#include <bits/stdc++.h>
using namespace std;
#define  MX  100005

vector<int> adj[MX + 5], revAdj[MX + 5], components;
stack<int> S;
int n, m;
bool vis[MX + 5];

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
   components.push_back(nd);
   for (int ch : revAdj[nd])
      if (!vis[ch])
         dfs2(ch);
}
int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
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


   vector<int> ans;
   while (!S.empty()) {
      int tp = S.top(); S.pop();
      if (!vis[tp]) {
         ans.push_back(tp);
         dfs2(tp);
      }
   }
   if (ans.size() <= 1)
      cout << "YES\n";
   else {
      cout << "NO\n";
      cout << ans[ans.size() - 1] << " " << ans[ans.size() - 2] << endl;
   }

}