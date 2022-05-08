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

void Solve(int tc)
{
   int n, m, cnt = 0;
   priority_queue<PII> Q;
   deque<PII> dq;

   cin >> n >> m;
   int ar[n], ans[n];

   rep(i, 0, n - 1) {
      cin >> ar[i];
      dq.pb({ar[i], i});
      Q.push({ar[i], i});
      ans[i] = 0;
   }

   while (!Q.empty()) {
      auto cur = Q.top();
      Q.pop();
      while (!dq.empty()) {
         auto tp = dq.front(); dq.pop_front();
         if (tp.ff == cur.ff) {
            ans[tp.ss] = ++cnt;
            break;
         }
         dq.pb(tp);
      }
   }
   // for (int x : ans) cout << x << " ";
   cout << ans[m] << "\n";
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