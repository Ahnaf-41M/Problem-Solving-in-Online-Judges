/*In my code i've denoted Vampires color as 1 and  Lykans colors as 0.
  In short, if a node is Vampire, every node adjacent to it will be
  Lykans,and vice versa.*/
#include<bits/stdc++.h>

#define pb   push_back
#define endl "\n"
#define ll   long long

#define W(t)            while(t--)
#define clr(a)          memset(a,0,sizeof(a))
#define rep(i,a,b)      for(i = a; i < b; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<int> adj[20005];
int n, m, color[20005];
set<int> edges;

int bfs(int nd)
{
     int Vampires = 1, Lykans = 0;
     color[nd] = 1;

     queue<int> Q;
     Q.push(nd);

     while (!Q.empty())
     {
          int tp = Q.front();
          Q.pop();

          for (int ch : adj[tp]) {
               if (color[ch] == -1) {
                    color[ch] = 1 - color[tp];
                    Q.push(ch);
                    if (color[ch] == 1) Vampires++;
                    else Lykans++;
               }
          }
     }
     return max(Vampires, Lykans);
}
void RESET()
{
     for (auto it = edges.begin(); it != edges.end(); it++) {
          adj[*it].clear();
          color[*it] = -1;
     }
     edges.clear();
}
int main()
{
     IOS
#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif
     int t, i, j; cin >> t;
     memset(color, -1, sizeof(color));

     rep(i, 1, t + 1)
     {
          cin >> n;

          rep(j, 0, n)
          {
               int x, y; cin >> x >> y;
               adj[x].pb(y); adj[y].pb(x);
               edges.insert(x); edges.insert(y);
          }
          int res = 0;

          for (auto it = edges.begin(); it != edges.end(); it++) {
               if (color[*it] == -1) {
                    res += bfs(*it);
               }
          }

          cout << "Case " << i << ": " << res << endl;
          RESET();
     }

     return 0;
}