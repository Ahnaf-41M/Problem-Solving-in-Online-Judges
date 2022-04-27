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

set<int> adj[MX];

void Solve(int tc)
{
   int N, R, ok = 1;
   cin >> N >> R;

   while (R--) {
      int id, code;
      cin >> id >> code;
      if (adj[id].find(code) != adj[id].end()) ok = 0;
      else adj[id].insert(code);
   }
   cout << "Scenario #" << tc << ": ";
   if (ok) cout << "possible\n";
   else cout << "impossible\n";

   rep(i, 1, N) adj[i].clear();
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   int T = 1;
   cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}