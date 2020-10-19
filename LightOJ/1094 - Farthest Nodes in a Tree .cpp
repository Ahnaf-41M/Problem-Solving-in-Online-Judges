/*First run a dfs for finding the max weighted path from 0.
  Then run another dfs for finding the maximum distance between
  two nodes.(Same as diameter finding of a tree)*/
#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 30005

vector<pair<int, int> > tree[mx];
int n, mx_ed_node, cur;
bool vis[mx];

void dfs(int nd, int cnt)
{
     vis[nd] = true;
     if (cur < cnt) {
          mx_ed_node = nd;
          cur = cnt;
     }

     for (auto ch : tree[nd])
     {
          int u = ch.first;
          int wt = ch.second;

          if (!vis[u])
               dfs(u, cnt + wt);
     }
}
int main()
{
     IOS
#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif
     int t, i, j, k; cin >> t;

     rep(k, 1, t + 1)
     {
          cin >> n;
          rep(i, 1, n)
          {
               int x, y, w; cin >> x >> y >> w;
               tree[x].pb({y, w}); tree[y].pb({x, w});
          }
          dfs(0, 0);
          rep(i, 0, n) vis[i] = false;
          cur = 0;
          dfs(mx_ed_node, 0);
          cout << "Case " << k << ": " << cur << endl;
          cur = 0;
          rep(i, 0, n) {
               tree[i].clear();
               vis[i] = false;
          }
     }


     return 0;
}