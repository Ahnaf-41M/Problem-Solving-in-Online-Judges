#include "bits/stdc++.h"
#define  ff           first
#define  ss           second
#define  MX           105
#define  pb           push_back
#define  int          long long
#define  PII          pair<int,char>
#define  endl         "\n"
#define  all(v)       v.begin(),v.end()
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;

vector<PII> adj[MX];
int col[MX], n;

bool bfs(int nd)
{
   col[nd] = 1;
   queue<int> Q;
   Q.push(nd);

   while (!Q.empty()) {
      int res = -1;
      nd = Q.front();
      Q.pop();

      for (auto ch : adj[nd]) {
         res = -1;
         if (ch.ss == 't') {
            if (col[nd] == 1) res = 1;
            else res = 0;
         }
         else {
            if (col[nd] == 1) res = 0;
            else res = 1;
         }
         if (col[ch.ff] == -1) col[ch.ff] = res, Q.push(ch.ff);
         else if (res != col[ch.ff]) return false;
      }
   }
   return true;
}
void Solve(int tc)
{
   memset(col, -1, sizeof(col));
   while (cin >> n && n) {
      bool ok = 1;
      rep(i, 1, n) {
         string s; int x;
         cin >> x >> s;
         adj[i].pb({x, s[0]});
      }

      rep(i, 1, n) {
         rep(j, 1, n) col[j] = -1;
         if (!bfs(i)) {
            ok = 0;
            break;
         }
      }

      cout << (!ok ? "PARADOX\n" : "NOT PARADOX\n");
      rep(i, 1, n) adj[i].clear(), col[i] = -1;
   }
}
signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   int T = 1;
   // cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      Solve(tc);
   }

   return 0;
}