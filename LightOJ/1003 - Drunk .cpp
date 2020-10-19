#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<int> adj[10005];
bool vis[10005], cycle;

void dfs(int nd)
{
     vis[nd] = true;
     if (cycle) return;

     for (int ch : adj[nd]) {
          if (!vis[ch]) {
               dfs(ch);
          }
          else {
               cycle = true;
               break;
          }
     }
     vis[nd]=false;
}
int main()
{
     IOS
#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif
     int t, i, j, m; cin >> t;

     rep(i, 1, t + 1)
     {
          cin >> m;
          cycle = false;
          string s1, s2;
          map<string, int> node;
          int ind = 1;
          W(m)
          {
               cin >> s1 >> s2;
               if (!node[s1]) node[s1] = ind++;
               if (!node[s2]) node[s2] = ind++;
               adj[node[s1]].pb(node[s2]);
          }
          rep(j, 1, ind)
          {
               if (!vis[j])
                    dfs(j);
          }
          rep(j, 1, ind) {
               adj[j].clear();
               vis[j] = false;
          }
          if (cycle)
               cout << "Case " << i << ": No\n";
          else
               cout << "Case " << i << ": Yes\n";
     }

     return 0;
}