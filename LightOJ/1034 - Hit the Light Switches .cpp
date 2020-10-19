#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 10005
#define pii pair<int,int>

vector<int> adj[mx];
bool vis[mx];
int n, m, in_deg[mx];
vector<int> Q;

void dfs(int nd, int type)
{
  vis[nd] = true;

  for (int ch : adj[nd])
    if (!vis[ch])
      dfs(ch, type);
  if (!type)
    Q.pb(nd);
}
int main()
{
  IOS
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int i, j, t; cin >> t;

  rep(i, 1, t + 1)
  {
    cin >> n >> m;
    W(m)
    {
      int x, y; cin >> x >> y;
      adj[x].pb(y);
      in_deg[y]++;
    }
    int ans = 0;
    rep(j, 1, n + 1) {
      if (!vis[j]) {
        dfs(j, 0);
      }
    }
    rep(j, 1, n + 1) vis[j] = false;
    for (j = Q.size()-1; j >= 0; j--)
      if (!vis[Q[j]]) {
        ans++;
        dfs(Q[j], 1);
      }
    cout << "Case " << i << ": " << ans << endl;
    rep(j, 1, n + 1) {
      adj[j].clear();
      vis[j] = false;
      in_deg[j] = 0;
    }
    Q.clear();
  }

  return 0;
}
