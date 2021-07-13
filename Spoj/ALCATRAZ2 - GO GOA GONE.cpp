#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           100005
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,int>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

int adj[10][10], ar[10];
vector<int> sets[(1 << 9)];

int Check(vector<int> v)
{
   int cur = 0;
   rep(i, 0, v.size() - 1) {
      cur += ar[v[i]];
      rep(j, i + 1, v.size() - 1) {
         if (adj[v[i]][v[j]])
            return false;
      }
   }
   return cur;
}
void Solve(int tc)
{
   int ans = 0;
   rep(i, 0, 7) {
      cin >> ar[i];
      ans = max(ar[i], ans);
   }

   int P;
   cin >> P;
   while (P--) {
      int x, y; cin >> x >> y;
      x--, y--;
      adj[x][y]++, adj[y][x]++;
   }

   for (int i = 0; i < (1 << 8); i++)
      for (int j = 0; j < 8; j++)
         if (i & (1 << j))
            sets[i].pb(j);

   for (int i = 0; i < (1 << 8); i++)
      if (sets[i].size())
         ans = max(ans, Check(sets[i]));
   cout << ans << "\n";

}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   int T = 1;
   //cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}